/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 16:07:09 by gbodur            #+#    #+#             */
/*   Updated: 2026/03/28 12:29:56 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

using std::cout;
using std::cerr;
using std::endl;
using std::stringstream;
using std::srand;
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
	int		testCount;
	Base	*generatedBase;

	if (argc != 2)
	{
		cerr << "Error: Invalid number of arguments." << endl;
		cerr << "Usage: ./identify <test_count>" << endl;
		return (1);
	}
	if (!parseInt(argv[1], testCount))
	{
		cerr << "Error: Test count must be a pure integer." << endl;
		return (1);
	}
	if (testCount <= 0)
	{
		cerr << "Error: Test count must be greater than zero." << endl;
		return (1);
	}
	srand(time(NULL));
	for (int i = 0; i < testCount; i++)
	{
		generatedBase = generate();
		cout << "---- Test " << i + 1 << " ----" << endl;
		cout << "Pointer identify: ";
		identify(generatedBase);
		cout << "Reference identify: ";
		identify(*generatedBase);
		delete generatedBase;
	}
	return (0);
}
