/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 20:29:00 by gbodur            #+#    #+#             */
/*   Updated: 2026/11/12 10:58:14 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <sys/time.h>
#include "PmergeMe.hpp"

using std::cout;
using std::cerr;
using std::endl;

static void currentTime(struct timeval &tv)
{
	if (gettimeofday(&tv, NULL) != 0)
		throw runtime_error("Error: could not read the clock.");
}

static double elapsedMicroseconds(const struct timeval &start, const struct timeval &end)
{
	double seconds = static_cast<double>(end.tv_sec - start.tv_sec);
	double micros = static_cast<double>(end.tv_usec - start.tv_usec);

	return seconds * 1000000.0 + micros;
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
		struct timeval start;
		struct timeval end;

		currentTime(start);
		sorter.fillVector(argc, argv);
		sorter.sortVector();
		currentTime(end);
		double vectorTime = elapsedMicroseconds(start, end);

		currentTime(start);
		sorter.fillDeque(argc, argv);
		sorter.sortDeque();
		currentTime(end);
		double dequeTime = elapsedMicroseconds(start, end);

		if (!sorter.containersMatch())
			throw runtime_error("Error: vector and deque results differ.");

		sorter.printArguments("Before: ", argc, argv);
		sorter.printVector("After:  ");

		cout << std::fixed << std::setprecision(0);
		cout << "Time to process a range of " << sorter.getVectorSize()
			 << " elements with std::vector : " << vectorTime << " us" << endl;
		cout << "Time to process a range of " << sorter.getDequeSize()
			 << " elements with std::deque  : " << dequeTime << " us" << endl;
	}
	catch (const std::exception &e)
	{
		cerr << e.what() << endl;
		return 1;
	}

	return 0;
}
