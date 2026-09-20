/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 20:29:02 by gbodur            #+#    #+#             */
/*   Updated: 2026/09/20 00:28:33 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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

void PmergeMe::printContainer(const string &prefix) const
{
	cout << prefix;
	for (size_t i = 0; i < _vector.size(); i++)
	{
		cout << _vector[i] << " ";
	}
	cout << endl;
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

void PmergeMe::mergeInsertSortVector(vector<int> &arr)
{
	if (arr.size() < 2)
		return;

	bool hasStraggler = (arr.size() % 2 != 0);
	int straggler = -1;
	if (hasStraggler)
	{
		straggler = arr.back();
		arr.pop_back();
	}

	vector<pair<int, int> > pairs;
	for (size_t i = 0; i < arr.size(); i += 2)
	{
		if (arr[i] > arr[i + 1])
			pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
		else
			pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
	}

	for (size_t i = 1; i < pairs.size(); i++)
	{
		pair<int, int> key = pairs[i];
		int j = i - 1;
		while (j >= 0 && pairs[j].first > key.first)
		{
			pairs[j + 1] = pairs[j];
			j--;
		}
		pairs[j + 1] = key;
	}

	vector<int> mainChain;
	vector<int> pend;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		mainChain.push_back(pairs[i].first);
		pend.push_back(pairs[i].second);
	}

	if (!pend.empty())
		mainChain.insert(mainChain.begin(), pend[0]);

	size_t pendSize = pend.size();
	size_t jacobIndex = 3; 
	size_t currentJacob = getJacobsthal(jacobIndex);
	size_t lastJacob = 1;

	while (lastJacob < pendSize)
	{
		size_t maxIndex = std::min(currentJacob, pendSize);
		for (size_t i = maxIndex; i > lastJacob; --i)
		{
			int valueToInsert = pend[i - 1];
			vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), valueToInsert);
			mainChain.insert(pos, valueToInsert);
		}
		lastJacob = maxIndex;
		jacobIndex++;
		currentJacob = getJacobsthal(jacobIndex);
	}

	if (hasStraggler)
	{
		vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(pos, straggler);
	}
	arr = mainChain;
}

void PmergeMe::sortVector()
{
	mergeInsertSortVector(_vector);
}

void PmergeMe::mergeInsertSortDeque(deque<int> &arr)
{
	if (arr.size() < 2)
		return;

	bool hasStraggler = (arr.size() % 2 != 0);
	int straggler = -1;
	if (hasStraggler)
	{
		straggler = arr.back();
		arr.pop_back();
	}

	deque<pair<int, int> > pairs;
	for (size_t i = 0; i < arr.size(); i += 2)
	{
		if (arr[i] > arr[i + 1])
			pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
		else
			pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
	}

	for (size_t i = 1; i < pairs.size(); i++)
	{
		pair<int, int> key = pairs[i];
		int j = i - 1;
		while (j >= 0 && pairs[j].first > key.first)
		{
			pairs[j + 1] = pairs[j];
			j--;
		}
		pairs[j + 1] = key;
	}

	deque<int> mainChain;
	deque<int> pend;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		mainChain.push_back(pairs[i].first);
		pend.push_back(pairs[i].second);
	}

	if (!pend.empty())
		mainChain.push_front(pend[0]);

	size_t pendSize = pend.size();
	size_t jacobIndex = 3; 
	size_t currentJacob = getJacobsthal(jacobIndex);
	size_t lastJacob = 1;

	while (lastJacob < pendSize)
	{
		size_t maxIndex = std::min(currentJacob, pendSize);
		for (size_t i = maxIndex; i > lastJacob; --i)
		{
			int valueToInsert = pend[i - 1];
			deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), valueToInsert);
			mainChain.insert(pos, valueToInsert);
		}
		lastJacob = maxIndex;
		jacobIndex++;
		currentJacob = getJacobsthal(jacobIndex);
	}

	if (hasStraggler)
	{
		deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(pos, straggler);
	}
	arr = mainChain;
}

void PmergeMe::sortDeque()
{
	mergeInsertSortDeque(_deque);
}
