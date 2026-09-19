/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 20:29:04 by gbodur            #+#    #+#             */
/*   Updated: 2026/09/20 00:15:44 by gbodur           ###   ########.fr       */
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

using std::string;
using std::vector;
using std::deque;
using std::runtime_error;

class PmergeMe 
{
	private:
		vector<int> _vector;
		deque<int>  _deque;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void parseArguments(int argc, char **argv);
		void printContainer(const string &prefix, const vector<int> &cont) const;
};

#endif