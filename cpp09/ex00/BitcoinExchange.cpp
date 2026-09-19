/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 10:38:11 by gbodur            #+#    #+#             */
/*   Updated: 2026/09/19 18:29:40 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _database(other._database) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        this->_database = other._database;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const string& filename)
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
