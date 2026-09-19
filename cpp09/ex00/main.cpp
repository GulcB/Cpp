/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 10:38:15 by gbodur            #+#    #+#             */
/*   Updated: 2026/09/19 18:30:38 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "BitcoinExchange.hpp"

using std::cout;
using std::cerr;
using std::endl;
using std::exception;

int main(int argc, char **argv)
{
    if (argc != 2)
	{
        cerr << "Error: could not open file." << endl;
        return 1;
    }
    try
	{
        BitcoinExchange btc;
        btc.loadDatabase("data.csv");

        (void)argv;
        
    } catch (const exception &e)
	{
        cerr << e.what() << endl;
        return 1;
    }

    return 0;
}
