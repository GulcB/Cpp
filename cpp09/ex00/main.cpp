/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 10:38:15 by gbodur            #+#    #+#             */
/*   Updated: 2026/09/18 10:41:27 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"

using std::cout;
using std::cerr;
using std::endl;

int main(int argc, char **argv)
{
    if (argc != 2)
	{
        cerr << "Error: could not open file." << endl;
        return 1;
    }
    
    (void)argv;

    return 0;
}