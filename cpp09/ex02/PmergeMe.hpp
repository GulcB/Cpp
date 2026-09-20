/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 20:29:04 by gbodur            #+#    #+#             */
/*   Updated: 2026/09/20 00:21:45 by gbodur           ###   ########.fr       */
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
# include <sys/time.h>
# include <algorithm>

using std::string;
using std::vector;
using std::deque;
using std::pair;
using std::runtime_error;

class PmergeMe 
{
	private:
		vector<int> _vector;
		deque<int>  _deque;
		size_t getJacobsthal(size_t n) const;
		void mergeInsertSortVector(vector<int> &arr);
		void mergeInsertSortDeque(deque<int> &arr);
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void parseArguments(int argc, char **argv);
		void printContainer(const string &prefix) const;
		void sortVector();
		void sortDeque();
		
		size_t getVectorSize() const;
		size_t getDequeSize() const;
};

#endif