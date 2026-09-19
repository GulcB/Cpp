/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 20:28:38 by gbodur            #+#    #+#             */
/*   Updated: 2026/09/19 23:34:15 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <stdexcept>

using std::string;
using std::stack;
using std::runtime_error;
using std::size_t;

class RPN 
{
	private:
		stack<int> _stack;
		typedef int (RPN::*OperationPtr)(int, int) const;
		char			_operators[4];
		OperationPtr	_functions[4];

		int add(int a, int b) const;
		int sub(int a, int b) const;
		int mul(int a, int b) const;
		int div(int a, int b) const;

		bool isOperator(char c) const;
		void performOperation(char op);

	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		void calculate(const string &expression);
};

#endif