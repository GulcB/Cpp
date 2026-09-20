/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 20:29:00 by gbodur            #+#    #+#             */
/*   Updated: 2026/09/20 00:25:04 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PmergeMe.hpp"

using std::cout;
using std::cerr;
using std::endl;

long long getTimeMicroseconds()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000LL) + tv.tv_usec;
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		cerr << "Error" << endl;
		return 1;
	}

	try 
	{
		PmergeMe sorter;
		sorter.parseArguments(argc, argv);
		sorter.printContainer("Before: ");

		long long startVec = getTimeMicroseconds();
		sorter.sortVector();
		long long endVec = getTimeMicroseconds();

		long long startDeq = getTimeMicroseconds();
		sorter.sortDeque();
		long long endDeq = getTimeMicroseconds();

		sorter.printContainer("After:  ");

		cout << "Time to process a range of " << sorter.getVectorSize() 
			 << " elements with std::vector : " 
			 << (endVec - startVec) << " us" << endl;
			 
		cout << "Time to process a range of " << sorter.getDequeSize() 
			 << " elements with std::deque  : " 
			 << (endDeq - startDeq) << " us" << endl;
	}
	catch (const std::exception &e)
	{
		cerr << e.what() << endl;
		return 1;
	}

	return 0;
}
