/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 20:29:02 by gbodur            #+#    #+#             */
/*   Updated: 2026/11/12 10:54:10 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cctype>
#include <cerrno>
#include <climits>

using std::cout;
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

int PmergeMe::parsePositiveInt(const string &arg)
{
	size_t start = (!arg.empty() && arg[0] == '+') ? 1 : 0;

	if (start == arg.length())
		throw runtime_error("Error: invalid argument => \"" + arg + "\"");
	for (size_t i = start; i < arg.length(); i++)
	{
		if (!std::isdigit(static_cast<unsigned char>(arg[i])))
			throw runtime_error("Error: invalid argument => \"" + arg + "\"");
	}

	char *endptr;
	errno = 0;
	long value = std::strtol(arg.c_str(), &endptr, 10);

	if (*endptr != '\0' || errno == ERANGE || value > INT_MAX)
		throw runtime_error("Error: number out of range => " + arg);
	if (value <= 0)
		throw runtime_error("Error: not a positive integer => " + arg);
	return static_cast<int>(value);
}

void PmergeMe::fillVector(int argc, char **argv)
{
	_vector.clear();
	_vector.reserve(argc - 1);
	for (int i = 1; i < argc; i++)
		_vector.push_back(parsePositiveInt(argv[i]));
}

void PmergeMe::fillDeque(int argc, char **argv)
{
	_deque.clear();
	for (int i = 1; i < argc; i++)
		_deque.push_back(parsePositiveInt(argv[i]));
}

void PmergeMe::printArguments(const string &prefix, int argc, char **argv) const
{
	cout << prefix;
	for (int i = 1; i < argc; i++)
	{
		if (i > 1)
			cout << " ";
		cout << parsePositiveInt(argv[i]);
	}
	cout << endl;
}

void PmergeMe::printVector(const string &prefix) const
{
	cout << prefix;
	for (size_t i = 0; i < _vector.size(); i++)
	{
		if (i > 0)
			cout << " ";
		cout << _vector[i];
	}
	cout << endl;
}

bool PmergeMe::containersMatch() const
{
	if (_vector.size() != _deque.size())
		return false;
	for (size_t i = 0; i < _vector.size(); i++)
	{
		if (_vector[i] != _deque[i])
			return false;
	}
	return true;
}

size_t PmergeMe::getVectorSize() const
{ 
	return _vector.size();
}

size_t PmergeMe::getDequeSize() const
{ 
	return _deque.size();
}

size_t PmergeMe::getJacobsthal(size_t n) const
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	size_t prev1 = 1;
	size_t prev2 = 0;
	size_t current = 0;
	for (size_t i = 2; i <= n; ++i)
	{
		current = prev1 + 2 * prev2;
		prev2 = prev1;
		prev1 = current;
	}
	return current;
}

vector<size_t> PmergeMe::fordJohnsonVector(const vector<int> &keys) const
{
	size_t n = keys.size();
	vector<size_t> chain;

	if (n == 0)
		return chain;
	if (n == 1)
	{
		chain.push_back(0);
		return chain;
	}

	size_t pairCount = n / 2;
	vector<size_t> larger(pairCount);
	vector<size_t> smaller(pairCount);
	vector<int> largerKeys(pairCount);

	for (size_t k = 0; k < pairCount; k++)
	{
		size_t first = 2 * k;
		size_t second = first + 1;

		if (keys[second] < keys[first])
		{
			larger[k] = first;
			smaller[k] = second;
		}
		else
		{
			larger[k] = second;
			smaller[k] = first;
		}
		largerKeys[k] = keys[larger[k]];
	}

	vector<size_t> pairOrder = fordJohnsonVector(largerKeys);

	vector<size_t> largerPos(pairCount);

	chain.reserve(n);
	chain.push_back(smaller[pairOrder[0]]);
	for (size_t j = 0; j < pairCount; j++)
	{
		chain.push_back(larger[pairOrder[j]]);
		largerPos[j] = j + 1;
	}

	size_t pendCount = pairCount + (n % 2);
	size_t lastJacob = 1;
	size_t jacobIndex = 3;

	while (lastJacob < pendCount)
	{
		size_t currentJacob = std::min(getJacobsthal(jacobIndex), pendCount);

		for (size_t i = currentJacob; i > lastJacob; i--)
		{
			size_t item;
			size_t searchEnd;

			if (i <= pairCount)
			{
				item = smaller[pairOrder[i - 1]];
				searchEnd = largerPos[i - 1];
			}
			else
			{
				item = n - 1;
				searchEnd = chain.size();
			}

			size_t pos = binarySearchVector(chain, keys, keys[item], searchEnd);

			chain.insert(chain.begin() + pos, item);
			for (size_t j = 0; j < pairCount; j++)
			{
				if (largerPos[j] >= pos)
					largerPos[j]++;
			}
		}
		lastJacob = currentJacob;
		jacobIndex++;
	}
	return chain;
}


size_t PmergeMe::binarySearchVector(const vector<size_t> &chain,
	const vector<int> &keys, int value, size_t end) const
{
	size_t low = 0;
	size_t high = end;

	while (low < high)
	{
		size_t mid = low + (high - low) / 2;

		if (keys[chain[mid]] < value)
			low = mid + 1;
		else
			high = mid;
	}
	return low;
}

void PmergeMe::sortVector()
{
	vector<size_t> order = fordJohnsonVector(_vector);
	vector<int> sorted;

	sorted.reserve(order.size());
	for (size_t i = 0; i < order.size(); i++)
		sorted.push_back(_vector[order[i]]);
	_vector.swap(sorted);
}

deque<size_t> PmergeMe::fordJohnsonDeque(const deque<int> &keys) const
{
	size_t n = keys.size();
	deque<size_t> chain;

	if (n == 0)
		return chain;
	if (n == 1)
	{
		chain.push_back(0);
		return chain;
	}

	size_t pairCount = n / 2;
	deque<size_t> larger(pairCount);
	deque<size_t> smaller(pairCount);
	deque<int> largerKeys(pairCount);

	for (size_t k = 0; k < pairCount; k++)
	{
		size_t first = 2 * k;
		size_t second = first + 1;

		if (keys[second] < keys[first])
		{
			larger[k] = first;
			smaller[k] = second;
		}
		else
		{
			larger[k] = second;
			smaller[k] = first;
		}
		largerKeys[k] = keys[larger[k]];
	}

	deque<size_t> pairOrder = fordJohnsonDeque(largerKeys);
	deque<size_t> largerPos(pairCount);

	chain.push_back(smaller[pairOrder[0]]);
	for (size_t j = 0; j < pairCount; j++)
	{
		chain.push_back(larger[pairOrder[j]]);
		largerPos[j] = j + 1;
	}

	size_t pendCount = pairCount + (n % 2);
	size_t lastJacob = 1;
	size_t jacobIndex = 3;

	while (lastJacob < pendCount)
	{
		size_t currentJacob = std::min(getJacobsthal(jacobIndex), pendCount);

		for (size_t i = currentJacob; i > lastJacob; i--)
		{
			size_t item;
			size_t searchEnd;

			if (i <= pairCount)
			{
				item = smaller[pairOrder[i - 1]];
				searchEnd = largerPos[i - 1];
			}
			else
			{
				item = n - 1;
				searchEnd = chain.size();
			}

			size_t pos = binarySearchDeque(chain, keys, keys[item], searchEnd);

			chain.insert(chain.begin() + pos, item);
			for (size_t j = 0; j < pairCount; j++)
			{
				if (largerPos[j] >= pos)
					largerPos[j]++;
			}
		}
		lastJacob = currentJacob;
		jacobIndex++;
	}
	return chain;
}

size_t PmergeMe::binarySearchDeque(const deque<size_t> &chain,
	const deque<int> &keys, int value, size_t end) const
{
	size_t low = 0;
	size_t high = end;

	while (low < high)
	{
		size_t mid = low + (high - low) / 2;

		if (keys[chain[mid]] < value)
			low = mid + 1;
		else
			high = mid;
	}
	return low;
}

void PmergeMe::sortDeque()
{
	deque<size_t> order = fordJohnsonDeque(_deque);
	deque<int> sorted;

	for (size_t i = 0; i < order.size(); i++)
		sorted.push_back(_deque[order[i]]);
	_deque.swap(sorted);
}
