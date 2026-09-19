/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 20:29:10 by gbodur            #+#    #+#             */
/*   Updated: 2026/09/19 23:14:57 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

using std::cerr;
using std::endl;

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		cerr << "Error" << endl;
		return 1;
	}
	RPN rpn;
	rpn.calculate(argv[1]);

	return 0;
}
