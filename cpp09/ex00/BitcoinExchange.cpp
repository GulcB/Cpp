/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 10:38:11 by gbodur            #+#    #+#             */
/*   Updated: 2026/09/19 20:12:42 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

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

void BitcoinExchange::loadDatabase(const string &filename)
{
    ifstream file(filename.c_str());
    if (!file.is_open())
        throw runtime_error("Error: could not open database file.");

    string line;
    std::getline(file, line);

    while (std::getline(file, line))
	{
        size_t delimPos = line.find(',');
        if (delimPos != string::npos)
		{
            string date = line.substr(0, delimPos);
            string rateStr = line.substr(delimPos + 1);
            float rate = std::atof(rateStr.c_str());
            _database[date] = rate;
        }
    }
    file.close();
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
        if (!isdigit(date[i]))
			return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 1900 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    return true;
}

float BitcoinExchange::parseValue(const string &valStr) const
{
    char *endptr;
    double parsed = std::strtod(valStr.c_str(), &endptr);

    if (*endptr != '\0' && *endptr != 'f') 
        throw runtime_error("bad input => " + valStr);
    if (parsed < 0) 
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
    std::getline(file, line);

    while (std::getline(file, line))
    {
        if (line.empty())
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
        catch (const std::exception& e) 
        {
            cout << "Error: " << e.what() << endl;
        }
    }
    file.close();
}
