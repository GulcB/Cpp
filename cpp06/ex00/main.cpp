/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 13:23:27 by gbodur            #+#    #+#             */
/*   Updated: 2026/03/28 12:25:58 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

using std::cerr;
using std::endl;

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		cerr << "Error: Invalid number of arguments." << endl;
		cerr << "Usage: ./convert <literal>" << endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}
