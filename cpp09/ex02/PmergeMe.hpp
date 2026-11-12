/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 20:29:04 by gbodur            #+#    #+#             */
/*   Updated: 2026/11/12 10:58:10 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <stdexcept>
# include <cstdlib>
# include <algorithm>
# include <cstddef>

using std::string;
using std::vector;
using std::deque;
using std::runtime_error;

class PmergeMe 
{
	private:
		vector<int> _vector;
		deque<int>  _deque;
		static int parsePositiveInt(const string &arg);
		size_t getJacobsthal(size_t n) const;
		vector<size_t> fordJohnsonVector(const vector<int> &keys) const;
		size_t binarySearchVector(const vector<size_t> &chain,
			const vector<int> &keys, int value, size_t end) const;
		deque<size_t> fordJohnsonDeque(const deque<int> &keys) const;
		size_t binarySearchDeque(const deque<size_t> &chain,
			const deque<int> &keys, int value, size_t end) const;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void fillVector(int argc, char **argv);
		void fillDeque(int argc, char **argv);
		void sortVector();
		void sortDeque();
		bool containersMatch() const;

		void printArguments(const string &prefix, int argc, char **argv) const;
		void printVector(const string &prefix) const;

		size_t getVectorSize() const;
		size_t getDequeSize() const;
};

#endif
