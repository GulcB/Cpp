/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 09:10:46 by gbodur            #+#    #+#             */
/*   Updated: 2026/08/24 12:55:43 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>
#include <sstream>


using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::list;
using std::exception;
using std::stringstream;

int main(int argc, char **argv)
{
	int count = 10000;

    if (argc > 2)
    {
        cerr << "Error: Invalid arguments." << endl;
        cerr << "Usage: ./span [number_of_elements]" << endl;
        return 1;
    }

    if (argc == 2)
    {
        stringstream ss(argv[1]);
        if (!(ss >> count) || !ss.eof() || count < 0)
        {
            cerr << "Error: Please provide a single non-negative integer for the number of elements." << endl;
    		cerr << "Usage: ./span [number_of_elements]" << endl;
    		return 1;
        }
    }
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
        emptySpan.shortestSpan();
    }
    catch (exception &e)
    {
        cerr << "Empty Span caught successfully: " << e.what() << endl;
    }

    try
    {
        Span oneElementSpan(10);
        oneElementSpan.addNumber(42);
        oneElementSpan.longestSpan();
    }
    catch (exception &e)
    {
        cerr << "One-element Span caught successfully: " << e.what() << endl;
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

    cout << "\n--- 4. Dynamic Data Test (" << count << " Elements) ---" << endl;
    try
	{
        Span dynamicSpan(count);
        vector<int> randomNumbers;
        
        std::srand(static_cast<unsigned int>(std::time(NULL)));
        for (int i = 0; i < count; ++i) 
		{
            randomNumbers.push_back(std::rand()); 
        }
		if (count <= 100)
		{
		    cout << "Generated numbers: ";
		    for (vector<int>::const_iterator it = randomNumbers.begin();
		         it != randomNumbers.end(); ++it)
		    {
		        cout << *it << " ";
		    }
		    cout << endl;
		}
        dynamicSpan.addNumber(randomNumbers.begin(), randomNumbers.end());
        
        cout << "Successfully added " << count << " numbers via Iterators!" << endl;
        cout << "Dynamic Shortest: " << dynamicSpan.shortestSpan() << endl;
        cout << "Dynamic Longest: " << dynamicSpan.longestSpan() << endl;
    }
    catch (exception &e)
	{
        cerr << e.what() << endl;
    }

    cout << "\n--- 5. Range Test with std::list Iterators ---" << endl;
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