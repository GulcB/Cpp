/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 13:47:37 by gbodur            #+#    #+#             */
/*   Updated: 2026/03/28 12:26:42 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

using std::cout;
using std::endl;
using std::string;
using std::ostringstream;
using std::fixed;
using std::setprecision;

static bool isNan(double value)
{
	return (value != value);
}

static bool isInf(double value)
{
	return (!isNan(value) && (value == std::numeric_limits<double>::infinity()
			|| value == -std::numeric_limits<double>::infinity()));
}

static void displayImpossible(void)
{
	cout << "char: impossible" << endl;
	cout << "int: impossible" << endl;
	cout << "float: impossible" << endl;
	cout << "double: impossible" << endl;
}

static t_scalarType findType(const string &literal)
{
	size_t	i;
	bool	hasDot;
	bool	hasDigit;

	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		return (TYPE_FLOAT);
	if (literal == "nan" || literal == "+inf" || literal == "-inf")
		return (TYPE_DOUBLE);
	if (literal.length() == 1
		&& !std::isdigit(static_cast<unsigned char>(literal[0])))
		return (TYPE_CHAR);
	i = 0;
	if (literal.empty())
		return (TYPE_INVALID);
	if (literal[i] == '+' || literal[i] == '-')
		i++;
	if (i == literal.length())
		return (TYPE_INVALID);
	hasDot = false;
	hasDigit = false;
	while (i < literal.length())
	{
		if (std::isdigit(static_cast<unsigned char>(literal[i])))
			hasDigit = true;
		else if (literal[i] == '.' && !hasDot)
			hasDot = true;
		else
			break ;
		i++;
	}
	if (!hasDigit)
		return (TYPE_INVALID);
	if (i == literal.length() && !hasDot)
		return (TYPE_INT);
	if (i == literal.length() && hasDot)
		return (TYPE_DOUBLE);
	if (i + 1 == literal.length() && literal[i] == 'f' && hasDot)
		return (TYPE_FLOAT);
	return (TYPE_INVALID);
}

static bool parseLiteral(const string &literal, t_scalarType scalarType,
	double &doubleLiteral)
{
	char	*endPtr;
	long	intLiteral;
	double	temp;
	string	number;

	if (scalarType == TYPE_CHAR)
	{
		doubleLiteral = static_cast<double>(literal[0]);
		return (true);
	}
	if (scalarType == TYPE_INT)
	{
		errno = 0;
		intLiteral = std::strtol(literal.c_str(), &endPtr, 10);
		if (*endPtr != '\0' || errno == ERANGE
			|| intLiteral < std::numeric_limits<int>::min()
			|| intLiteral > std::numeric_limits<int>::max())
			return (false);
		doubleLiteral = static_cast<double>(intLiteral);
		return (true);
	}
	number = literal;
	if (scalarType == TYPE_FLOAT)
		number = literal.substr(0, literal.length() - 1);
	errno = 0;
	temp = std::strtod(number.c_str(), &endPtr);
	if (*endPtr != '\0' || errno == ERANGE)
		return (false);
	if (scalarType == TYPE_FLOAT)
	{
		if (!isInf(temp)
			&& (temp > std::numeric_limits<float>::max()
				|| temp < -std::numeric_limits<float>::max()))
			return (false);
		doubleLiteral = static_cast<double>(static_cast<float>(temp));
		return (true);
	}
	doubleLiteral = temp;
	return (true);
}

static string formatOutput(double value, int precision, const string &suffix)
{
	ostringstream	output;
	double			integerPart;

	if (isNan(value))
		return ("nan" + suffix);
	if (value == std::numeric_limits<double>::infinity())
		return ("+inf" + suffix);
	if (value == -std::numeric_limits<double>::infinity())
		return ("-inf" + suffix);
	if (modf(value, &integerPart) == 0.0)
		output << fixed << setprecision(1) << value;
	else
		output << setprecision(precision) << value;
	return (output.str() + suffix);
}

static void displayScalarTypes(double doubleLiteral)
{
	char	charLiteral;

	cout << "char: ";
	if (isNan(doubleLiteral) || isInf(doubleLiteral)
		|| doubleLiteral < std::numeric_limits<char>::min()
		|| doubleLiteral > std::numeric_limits<char>::max())
		cout << "impossible" << endl;
	else
	{
		charLiteral = static_cast<char>(doubleLiteral);
		if (charLiteral < 32 || charLiteral > 126)
			cout << "Non displayable" << endl;
		else
			cout << "'" << charLiteral << "'" << endl;
	}
	cout << "int: ";
	if (isNan(doubleLiteral) || isInf(doubleLiteral)
		|| doubleLiteral < std::numeric_limits<int>::min()
		|| doubleLiteral > std::numeric_limits<int>::max())
		cout << "impossible" << endl;
	else
		cout << static_cast<int>(doubleLiteral) << endl;
	cout << "float: ";
	if (!isNan(doubleLiteral) && !isInf(doubleLiteral)
		&& (doubleLiteral > std::numeric_limits<float>::max()
			|| doubleLiteral < -std::numeric_limits<float>::max()))
		cout << "impossible" << endl;
	else
		cout << formatOutput(static_cast<double>(static_cast<float>(doubleLiteral)),
			7, "f") << endl;
	cout << "double: " << formatOutput(doubleLiteral, 15, "") << endl;
}

void ScalarConverter::convert(const string &literal)
{
	t_scalarType	scalarType;
	double			doubleLiteral;

	scalarType = findType(literal);
	if (scalarType == TYPE_INVALID || !parseLiteral(literal, scalarType,
			doubleLiteral))
	{
		displayImpossible();
		return ;
	}
	displayScalarTypes(doubleLiteral);
}
