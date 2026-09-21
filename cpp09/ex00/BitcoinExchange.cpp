/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 10:38:11 by gbodur            #+#    #+#             */
/*   Updated: 2026/09/21 14:07:27 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cerrno>
#include <limits>

using std::cout;
using std::endl;

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _database(other._database) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        this->_database = other._database;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}


float BitcoinExchange::parseDatabaseRate(const string &rateStr) const
{
    if (rateStr.empty() ||
        rateStr.find_first_not_of("0123456789+-.eE") != string::npos)
        throw runtime_error("invalid database rate => " + rateStr);

    char *endptr;
    errno = 0;
    double rate = std::strtod(rateStr.c_str(), &endptr);

    if (endptr == rateStr.c_str() || *endptr != '\0' ||
        errno == ERANGE || rate < 0.0 ||
        rate > std::numeric_limits<float>::max())
        throw runtime_error("invalid database rate => " + rateStr);

    return static_cast<float>(rate);
}

void BitcoinExchange::loadDatabase(const string &filename)
{
    ifstream file(filename.c_str());

    if (!file.is_open())
        throw runtime_error("Error: could not open database file.");

    string line;

    if (!std::getline(file, line) ||
        trim(line) != "date,exchange_rate")
        throw runtime_error("Error: invalid database header.");

    map<string, float> newDatabase;

    while (std::getline(file, line))
    {
        if (trim(line).empty())
            continue;

        size_t delim = line.find(',');

        if (delim == string::npos)
            throw runtime_error("Error: invalid database row => " + line);

        string date = trim(line.substr(0, delim));
        string rateStr = trim(line.substr(delim + 1));

        if (!isValidDate(date))
            throw runtime_error("Error: invalid database date => " + date);

        float rate = parseDatabaseRate(rateStr);

        if (newDatabase.find(date) != newDatabase.end())
            throw runtime_error("Error: duplicate database date => " + date);

        newDatabase[date] = rate;
    }

    if (file.bad() || newDatabase.empty())
        throw runtime_error("Error: invalid or empty database.");

    _database.swap(newDatabase);
}

string BitcoinExchange::trim(const string &str) const
{
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == string::npos)
		return "";
    size_t last = str.find_last_not_of(" \t\r\n");
    return (str.substr(first, (last - first + 1)));
}

bool BitcoinExchange::isValidDate(const string &date) const
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    
    for (int i = 0; i < 10; i++)
	{
        if (i == 4 || i == 7)
			continue;
        if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 1 || month < 1 || month > 12)
        return false;

	const int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	int maxDay = daysInMonth[month - 1];
	
	bool isLeapYear = (year % 400 == 0 ||
                      (year % 4 == 0 && year % 100 != 0));

	if (month == 2 && isLeapYear)
		maxDay = 29;

    return (day >= 1 && day <= maxDay);
}

float BitcoinExchange::parseValue(const string &valStr) const
{
	if (valStr.empty() ||
        valStr.find_first_not_of("0123456789+-.eEf") != string::npos)
        throw runtime_error("bad input => " + valStr);

    char *endptr;
    double parsed = std::strtod(valStr.c_str(), &endptr);

    if (endptr == valStr.c_str() ||
		(*endptr != '\0' && !(*endptr == 'f' && endptr[1] == '\0')))
        throw runtime_error("bad input => " + valStr);
    if (parsed < 0.0) 
        throw runtime_error("not a positive number.");
    if (parsed > 1000.0) 
        throw runtime_error("too large a number.");
    return (static_cast<float>(parsed));
}


void BitcoinExchange::processInput(const string &filename)
{
    ifstream file(filename.c_str());

    if (!file.is_open())
    {
        cout << "Error: could not open file." << endl;
        return;
    }

    string line;
    bool firstLine = true;

    while (std::getline(file, line))
    {
        if (firstLine)
        {
            firstLine = false;

            if (trim(line) == "date | value")
                continue;
        }
        if (trim(line).empty())
            continue;
        try
        {
            size_t delim = line.find('|');

            if (delim == string::npos)
                throw runtime_error("bad input => " + line);

            string date = trim(line.substr(0, delim));
            string valStr = trim(line.substr(delim + 1));

            if (!isValidDate(date))
                throw runtime_error("bad input => " + date);

            float val = parseValue(valStr);
            map<string, float>::const_iterator it = _database.upper_bound(date);

            if (it == _database.begin())
                throw runtime_error("date is older than any record in database.");
            --it;
            cout << date << " => " << val << " = " << (val * it->second) << endl;
        }
        catch (const std::exception &e)
        {
            cout << "Error: " << e.what() << endl;
        }
    }
}
