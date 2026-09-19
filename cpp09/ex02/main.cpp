/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 20:29:00 by gbodur            #+#    #+#             */
/*   Updated: 2026/09/20 00:16:04 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PmergeMe.hpp"

using std::cerr;
using std::endl;

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		cerr << "Error: provide a sequence of positive integers." << endl;
		return 1;
	}
	try 
	{
		PmergeMe sorter;
		sorter.parseArguments(argc, argv);
	}
	catch (const std::exception &e)
	{
		cerr << e.what() << endl;
		return 1;
	}

	return 0;
}