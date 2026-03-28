/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:53:07 by gbodur            #+#    #+#             */
/*   Updated: 2026/03/27 17:53:08 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <sstream>
#include <string>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::stringstream;

static bool parseInt(char *arg, int &output)
{
	stringstream	ss;

	ss << arg;
	ss >> output;
	if (ss.fail() || !ss.eof())
		return (false);
	return (true);
}

template <typename T>
void printElement(const T &element)
{
	cout << element << " ";
}

void incrementInt(int &number)
{
	number++;
}

void addSuffix(string &word)
{
	word += "_x";
}

int main(int argc, char **argv)
{
	int				arraySize;
	int				*numbers;
	string			*words;
	double			*decimalValues;
	const double	*constValues;
	stringstream	ss;

	if (argc != 2)
	{
		cerr << "Error: Invalid number of arguments." << endl;
		cerr << "Usage: ./iter <array_size>" << endl;
		return (1);
	}
	if (!parseInt(argv[1], arraySize))
	{
		cerr << "Error: Array size must be a pure integer." << endl;
		return (1);
	}
	if (arraySize <= 0)
	{
		cerr << "Error: Array size must be greater than zero." << endl;
		return (1);
	}
	if (arraySize > 20)
	{
		cerr << "Error: Array size is too large for display test." << endl;
		return (1);
	}
	numbers = new int[arraySize];
	words = new string[arraySize];
	decimalValues = new double[arraySize];
	constValues = decimalValues;
	for (int i = 0; i < arraySize; i++)
	{
		numbers[i] = i * 10;
		ss.str("");
		ss.clear();
		ss << "word" << i;
		words[i] = ss.str();
		decimalValues[i] = i + 0.5;
	}
	cout << "--- INT ARRAY BEFORE ---" << endl;
	iter(numbers, static_cast<unsigned int>(arraySize), printElement<int>);
	cout << endl;
	iter(numbers, static_cast<unsigned int>(arraySize), incrementInt);
	cout << "--- INT ARRAY AFTER ---" << endl;
	iter(numbers, static_cast<unsigned int>(arraySize), printElement<int>);
	cout << "\n\n--- STRING ARRAY BEFORE ---" << endl;
	iter(words, static_cast<unsigned int>(arraySize), printElement<string>);
	cout << endl;
	iter(words, static_cast<unsigned int>(arraySize), addSuffix);
	cout << "--- STRING ARRAY AFTER ---" << endl;
	iter(words, static_cast<unsigned int>(arraySize), printElement<string>);
	cout << "\n\n--- CONST DOUBLE ARRAY ---" << endl;
	iter(constValues, static_cast<unsigned int>(arraySize), printElement<double>);
	cout << endl;
	delete [] numbers;
	delete [] words;
	delete [] decimalValues;
	return (0);
}
