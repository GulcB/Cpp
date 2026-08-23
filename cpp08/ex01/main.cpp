/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 09:10:46 by gbodur            #+#    #+#             */
/*   Updated: 2026/08/23 06:38:41 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::list;
using std::exception;

int main()
{
    cout << "--- 1. Subject Basic Test ---" << endl;
    try
	{
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        cout << "Shortest: " << sp.shortestSpan() << endl;
        cout << "Longest: " << sp.longestSpan() << endl;
    }
    catch (exception &e)
	{
        cerr << e.what() << endl;
    }

    cout << "\n--- 2. Exception Testing (Empty / 1 Element) ---" << endl;
    try
	{
        Span emptySpan(10);
        emptySpan.addNumber(42);
        emptySpan.shortestSpan();
    }
    catch (exception &e)
	{
        cerr << "Caught successfully: " << e.what() << endl;
    }

    cout << "\n--- 3. Exception Testing (Capacity Overflow) ---" << endl;
    try
	{
        Span smallSpan(2);
        smallSpan.addNumber(1);
        smallSpan.addNumber(2);
        smallSpan.addNumber(3);
    }
    catch (exception &e)
	{
        cerr << "Caught successfully: " << e.what() << endl;
    }

    cout << "\n--- 4. Nerd Level: Iterator Range & Massive Data Test (100,000 Elements) ---" << endl;
    try
	{
        Span massiveSpan(100000);
        vector<int> randomNumbers;
        
        std::srand(std::time(NULL));
        for (int i = 0; i < 100000; ++i) 
		{
            randomNumbers.push_back(std::rand()); 
        }
        massiveSpan.addNumber(randomNumbers.begin(), randomNumbers.end());
        
        cout << "Successfully added 100,000 numbers via Iterators!" << endl;
        cout << "Massive Shortest: " << massiveSpan.shortestSpan() << endl;
        cout << "Massive Longest: " << massiveSpan.longestSpan() << endl;
    }
    catch (exception &e)
	{
        cerr << e.what() << endl;
    }

    cout << "\n--- 5. Polymorphism Test with std::list Iterators ---" << endl;
    try
	{
        Span listSpan(10);
        list<int> listNumbers;
        listNumbers.push_back(-500);
        listNumbers.push_back(500);
        listNumbers.push_back(0);

        listSpan.addNumber(listNumbers.begin(), listNumbers.end());
        cout << "List Iterators Longest: " << listSpan.longestSpan() << " (Expected 1000)" << endl;
    }
    catch (exception &e)
	{
        cerr << e.what() << endl;
    }

    return 0;
}