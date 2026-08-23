/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 09:10:57 by gbodur            #+#    #+#             */
/*   Updated: 2026/08/23 08:04:50 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <cstdlib>

using std::cout;
using std::endl;
using std::cerr;
using std::list;
using std::stack;

int main(int argc, char **argv)
{
    cout << "--- 1. Subject Mandatory Test ---" << endl;
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    cout << "Top element: " << mstack.top() << endl;
    
    mstack.pop();
    cout << "Size after pop: " << mstack.size() << endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    
    cout << "Stack contents:" << endl;
    while (it != ite)
    {
        cout << *it << endl;
        ++it;
    }
    stack<int> s(mstack);

    cout << "\n--- 2. std::list Comparison Test ---" << endl;
    list<int> mlist;
    mlist.push_back(5);
    mlist.push_back(17);
    cout << "Back element: " << mlist.back() << endl;
    
    mlist.pop_back();
    cout << "Size after pop_back: " << mlist.size() << endl;
    
    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(0);

    list<int>::iterator lit = mlist.begin();
    list<int>::iterator lite = mlist.end();
    
    ++lit;
    --lit;
    
    cout << "List contents:" << endl;
    while (lit != lite)
    {
        cout << *lit << endl;
        ++lit;
    }

    cout << "\n--- 3. Custom Argument Test ---" << endl;
    if (argc > 1)
    {
        MutantStack<int> argStack;
        for (int i = 1; i < argc; ++i)
        {
            argStack.push(std::atoi(argv[i]));
        }

        cout << "Arguments pushed to MutantStack. Elements:" << endl;
        for (MutantStack<int>::iterator argIt = argStack.begin(); argIt != argStack.end(); ++argIt)
        {
            cout << *argIt << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "No additional arguments provided. Run with './ex02 <numbers>' to test dynamic inputs." << endl;
    }

    return 0;
}