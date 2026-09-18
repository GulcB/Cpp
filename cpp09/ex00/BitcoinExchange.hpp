/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 10:38:13 by gbodur            #+#    #+#             */
/*   Updated: 2026/09/18 10:40:50 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>

using std::string;
using std::map;

class BitcoinExchange 
{
	private:
	    map<string, float> _database;
	public:
	    BitcoinExchange();
	    BitcoinExchange(const BitcoinExchange &other);
	    BitcoinExchange &operator=(const BitcoinExchange &other);
	    ~BitcoinExchange();
};

#endif