/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 20:29:02 by gbodur            #+#    #+#             */
/*   Updated: 2026/09/20 00:15:24 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

using std::cout;
using std::cerr;
using std::endl;

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : _vector(other._vector), _deque(other._deque) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->_vector = other._vector;
		this->_deque = other._deque;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::parseArguments(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		string arg = argv[i];
		if (arg.empty())
			throw runtime_error("Error: empty argument.");

		for (size_t j = 0; j < arg.length(); j++)
		{
			if (!isdigit(arg[j]) && !(j == 0 && arg[j] == '+'))
				throw runtime_error("Error: invalid character in sequence.");
		}
		long val = std::atol(arg.c_str());
		if (val < 0 || val > 2147483647)
			throw runtime_error("Error: number out of bounds.");
	
		_vector.push_back(static_cast<int>(val));
		_deque.push_back(static_cast<int>(val));
	}
}

void PmergeMe::printContainer(const string &prefix, const vector<int> &cont) const
{
	cout << prefix;
	for (size_t i = 0; i < cont.size(); i++)
	{
		cout << cont[i] << " ";
	}
	cout << endl;
}
