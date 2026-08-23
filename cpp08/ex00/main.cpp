/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 09:09:18 by gbodur            #+#    #+#             */
/*   Updated: 2026/08/23 06:24:30 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <sstream>
#include <string>

using std::cout;
using std::endl;
using std::cerr;
using std::vector;
using std::list;
using std::deque;
using std::string;
using std::stringstream;
using std::exception;

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        cerr << "Error: Invalid arguments." << endl;
        cerr << "Usage: ./easyfind \"<numbers separated by space>\" <value>" << endl;
        return 1;
    }
    
    vector<int> vec;
    stringstream ss(argv[1]); // Doğru constructor kullanımı
    int value;
    string remaining;
    
    while (ss >> value)
        vec.push_back(value);
    
    if (!ss.eof())
    {
        ss.clear();
        ss >> remaining;
        cerr << "Invalid character detected in container input: '" << remaining << "'" << endl;
        return 1;
    }

    stringstream targetStream(argv[2]); // Doğru constructor kullanımı
    int target;
    if (!(targetStream >> target) || !targetStream.eof())
    {
        cerr << "Target must be a valid integer." << endl;
        return 1;
    }

    runTest(vec, target, "std::vector");

    list<int> lst(vec.begin(), vec.end());
    runTest(lst, target, "std::list");

    deque<int> deq(vec.begin(), vec.end());
    runTest(deq, target, "std::deque");

    vector<int> emptyVec;
    runTest(emptyVec, target, "Empty std::vector");

    const list<int> constLst(vec.begin(), vec.end());
    runTest(constLst, target, "Const std::list");

    return 0;
}
