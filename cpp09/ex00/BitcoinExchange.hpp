/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 10:38:13 by gbodur            #+#    #+#             */
/*   Updated: 2026/09/21 14:15:48 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>
# include <fstream>
# include <stdexcept>
# include <cstdlib>

using std::string;
using std::map;
using std::ifstream;
using std::runtime_error;
using std::size_t;

class BitcoinExchange 
{
	private:
	    map<string, float> _database;
		string trim(const string &str) const;
    	bool isValidDate(const string &date) const;
    	float parseValue(const string &valStr) const;
		float parseDatabaseRate(const string &rateStr) const;
	public:
	    BitcoinExchange();
	    BitcoinExchange(const BitcoinExchange &other);
	    BitcoinExchange &operator=(const BitcoinExchange &other);
	    ~BitcoinExchange();

		void loadDatabase(const string &filename);
		void processInput(const string &filename);
};

#endif
