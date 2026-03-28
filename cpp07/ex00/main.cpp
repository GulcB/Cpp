/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:52:40 by gbodur            #+#    #+#             */
/*   Updated: 2026/03/27 17:52:41 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
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

int main(int argc, char **argv)
{
	int		leftNumber;
	int		rightNumber;
	string	leftWord;
	string	rightWord;

	if (argc != 5)
	{
		cerr << "Error: Invalid number of arguments." << endl;
		cerr << "Usage: ./whatever <int_a> <int_b> <string_a> <string_b>" << endl;
		return (1);
	}
	if (!parseInt(argv[1], leftNumber) || !parseInt(argv[2], rightNumber))
	{
		cerr << "Error: First two arguments must be pure integers." << endl;
		return (1);
	}
	leftWord = argv[3];
	rightWord = argv[4];
	cout << "--- INT TEST ---" << endl;
	cout << "Before swap: " << leftNumber << " " << rightNumber << endl;
	::swap(leftNumber, rightNumber);
	cout << "After swap: " << leftNumber << " " << rightNumber << endl;
	cout << "min: " << ::min(leftNumber, rightNumber) << endl;
	cout << "max: " << ::max(leftNumber, rightNumber) << endl;
	cout << "\n--- STRING TEST ---" << endl;
	cout << "Before swap: " << leftWord << " " << rightWord << endl;
	::swap(leftWord, rightWord);
	cout << "After swap: " << leftWord << " " << rightWord << endl;
	cout << "min: " << ::min(leftWord, rightWord) << endl;
	cout << "max: " << ::max(leftWord, rightWord) << endl;
	return (0);
}
