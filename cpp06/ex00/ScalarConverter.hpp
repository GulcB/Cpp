/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 14:00:00 by gbodur            #+#    #+#             */
/*   Updated: 2026/03/28 12:26:49 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cerrno>
#include <cctype>
#include <cmath>

using std::string;

enum t_scalarType
{
	TYPE_INVALID,
	TYPE_CHAR,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE
};

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &scalarConverter);
		ScalarConverter &operator=(const ScalarConverter &scalarConverter);
		~ScalarConverter();

	public:
		static void convert(const string &literal);
};

#endif
