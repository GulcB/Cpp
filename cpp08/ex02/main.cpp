/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 09:10:57 by gbodur            #+#    #+#             */
/*   Updated: 2026/08/24 13:18:17 by gbodur           ###   ########.fr       */
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
	cout << "\n--- 3. Copy / Assignment Test ---" << endl;

    MutantStack<int> copyStack(mstack);
    MutantStack<int> assignedStack;

    assignedStack = mstack;

    cout << "Original top: " << mstack.top() << endl;
    cout << "Copy top: " << copyStack.top() << endl;
    cout << "Assigned top: " << assignedStack.top() << endl;
	
	cout << "\n--- 4. Const Iterator Test ---" << endl;

    const MutantStack<int> constStack(mstack);

    cout << "Const stack contents: ";
    for (MutantStack<int>::const_iterator cit = constStack.begin();
         cit != constStack.end(); ++cit)
    {
        cout << *cit << " ";
    }
    cout << endl;

    cout << "\n--- 5. Reverse Iterator Test ---" << endl;

    cout << "Reverse stack contents: ";
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin();
         rit != mstack.rend(); ++rit)
    {
        cout << *rit << " ";
    }
    cout << endl;

    cout << "\n--- 6. Custom Argument Test ---" << endl;
    if (argc > 1)
    {
        MutantStack<int> argStack;
        for (int i = 1; i < argc; ++i)
        {
            argStack.push(std::atoi(argv[i]));
        }

        cout << "Arguments pushed to MutantStack. Elements: ";
        for (MutantStack<int>::iterator argIt = argStack.begin();
			argIt != argStack.end(); ++argIt)
        {
            cout << *argIt << " ";
        }
        cout << endl;
    }
    else
    {
        cerr << "No additional arguments provided." << endl;
		cout << "Usage: ./mutantStack <numbers>" << endl;
		
    }

    return 0;
}
