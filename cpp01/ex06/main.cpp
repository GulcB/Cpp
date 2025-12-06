/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 11:35:48 by gbodur            #+#    #+#             */
/*   Updated: 2025/12/06 12:19:08 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

using   std::stringstream;
using   std::string;
using   std::cerr;
using   std::cout;
using   std::endl;

int main(int argc, char **argv)
{
    Harl harl;

    if (argc != 2)
    {
        cerr << "Usage: <./harlFilter> <DEBUG or INFO or WARNING or ERROR>" << endl;
        return (1);
    }
    harl.complain(argv[1]);
    return (0);
}