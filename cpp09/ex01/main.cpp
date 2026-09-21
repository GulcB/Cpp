/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 20:29:10 by gbodur            #+#    #+#             */
/*   Updated: 2026/09/21 19:13:43 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <exception>

using std::cerr;
using std::endl;

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    try
    {
        RPN rpn;
        rpn.calculate(argv[1]);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
