/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:53:35 by gbodur            #+#    #+#             */
/*   Updated: 2026/03/27 17:53:36 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <exception>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::stringstream;
using std::exception;
using std::srand;
using std::rand;
using std::time;

static bool parseInt(char *arg, int &output)
{
	stringstream	ss;

	ss << arg;
	ss >> output;
	if (ss.fail() || !ss.eof())
		return (false);
	return (true);
}

int main(int argc, char **argv)
{
	int				arraySize;
	int				requestedIndex;
	int				*mirror;
	Array<int>		numbers;
	Array<int>		copyNumbers;
	Array<string>	words(3);
	Array<double>	emptyArray;

	if (argc != 3)
	{
		cerr << "Error: Invalid number of arguments." << endl;
		cerr << "Usage: ./array <size> <index>" << endl;
		return (1);
	}
	if (!parseInt(argv[1], arraySize) || !parseInt(argv[2], requestedIndex))
	{
		cerr << "Error: Size and index must be pure integers." << endl;
		return (1);
	}
	if (arraySize < 0)
	{
		cerr << "Error: Size cannot be negative." << endl;
		return (1);
	}
	if (arraySize > 1000)
	{
		cerr << "Error: Size is too large for test executable." << endl;
		return (1);
	}
	mirror = NULL;
	numbers = Array<int>(static_cast<unsigned int>(arraySize));
	if (arraySize > 0)
	{
		mirror = new int[arraySize];
		srand(time(NULL));
		for (int i = 0; i < arraySize; i++)
		{
			const int value = rand();
			numbers[static_cast<unsigned int>(i)] = value;
			mirror[i] = value;
		}
	}
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
		(void)test;
	}
	for (int i = 0; i < arraySize; i++)
	{
		if (mirror[i] != numbers[static_cast<unsigned int>(i)])
		{
			delete [] mirror;
			cerr << "Error: Mirror test failed." << endl;
			return (1);
		}
	}
	copyNumbers = numbers;
	if (numbers.size() > 0)
		numbers[0] = -999;
	words[0] = "hello";
	words[1] = "template";
	words[2] = "array";
	cout << "--- EMPTY ARRAY ---" << endl;
	cout << "Size: " << emptyArray.size() << endl;
	cout << "\n--- ORIGINAL INT ARRAY ---" << endl;
	for (unsigned int i = 0; i < numbers.size(); i++)
		cout << numbers[i] << " ";
	cout << endl;
	cout << "--- COPIED INT ARRAY ---" << endl;
	for (unsigned int i = 0; i < copyNumbers.size(); i++)
		cout << copyNumbers[i] << " ";
	cout << endl;
	cout << "\n--- STRING ARRAY ---" << endl;
	for (unsigned int i = 0; i < words.size(); i++)
		cout << words[i] << " ";
	cout << endl;
	cout << "\n--- INDEX TEST ---" << endl;
	cout << "Requested index: " << requestedIndex << endl;
	try
	{
		int value = numbers[static_cast<unsigned int>(requestedIndex)];
		cout << "Value: " << value << endl;
	}
	catch (const exception &e)
	{
		cout << "Exception: " << e.what() << endl;
	}
	delete [] mirror;
	return (0);
}
