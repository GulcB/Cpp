/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 20:29:08 by gbodur            #+#    #+#             */
/*   Updated: 2026/09/21 19:17:50 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <cctype>
#include <climits>

using std::cout;
using std::cerr;
using std::endl;

RPN::RPN() 
{
	_operators[0] = '+'; _functions[0] = &RPN::add;
	_operators[1] = '-'; _functions[1] = &RPN::sub;
	_operators[2] = '*'; _functions[2] = &RPN::mul;
	_operators[3] = '/'; _functions[3] = &RPN::div;
}

RPN::RPN(const RPN &other) : _stack(other._stack) 
{
	for (int i = 0; i < 4; i++)
	{
		this->_operators[i] = other._operators[i];
		this->_functions[i] = other._functions[i];
	}
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		this->_stack = other._stack;
		for (int i = 0; i < 4; i++)
		{
			this->_operators[i] = other._operators[i];
			this->_functions[i] = other._functions[i];
		}
	}
	return *this;
}

RPN::~RPN() {}

int RPN::add(int a, int b) const
{
    if ((b > 0 && a > INT_MAX - b) ||
        (b < 0 && a < INT_MIN - b))
        throw runtime_error("Error");

    return a + b;
}

int RPN::sub(int a, int b) const
{
    if ((b < 0 && a > INT_MAX + b) ||
        (b > 0 && a < INT_MIN + b))
        throw runtime_error("Error");

    return a - b;
}

int RPN::mul(int a, int b) const
{
    if (a > 0)
    {
        if ((b > 0 && a > INT_MAX / b) ||
            (b < 0 && b < INT_MIN / a))
            throw runtime_error("Error");
    }
    else if (a < 0)
    {
        if ((b > 0 && a < INT_MIN / b) ||
            (b < 0 && a < INT_MAX / b))
            throw runtime_error("Error");
    }

    return a * b;
}

int RPN::div(int a, int b) const
{
    if (b == 0 || (a == INT_MIN && b == -1))
        throw runtime_error("Error");

    return a / b;
}

bool RPN::isOperator(char c) const
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RPN::performOperation(char op)
{
	if (_stack.size() < 2)
		throw runtime_error("Error");

	int val2 = _stack.top();
	_stack.pop();
	int val1 = _stack.top();
	_stack.pop();

	for (int i = 0; i < 4; i++)
	{
		if (_operators[i] == op)
		{
			_stack.push((this->*(_functions[i]))(val1, val2));
			return;
		}
	}
	throw runtime_error("Error");
}

void RPN::calculate(const string &expression)
{
    std::istringstream input(expression);
    string token;

    while (!_stack.empty())
        _stack.pop();

    while (input >> token)
    {
        if (token.length() != 1)
            throw runtime_error("Error");

        unsigned char c = static_cast<unsigned char>(token[0]);

        if (std::isdigit(c))
            _stack.push(c - '0');
        else if (isOperator(c))
            performOperation(c);
        else
            throw runtime_error("Error");
    }

    if (_stack.size() != 1)
        throw runtime_error("Error");

    cout << _stack.top() << endl;
}
