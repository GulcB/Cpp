/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:42:56 by gbodur            #+#    #+#             */
/*   Updated: 2025/12/05 19:49:45 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

using   std::cerr;
using   std::endl;

int main(int argc, char **argv)
{
    Harl    harl;

    (void)argv;
    if(argc != 1)
    {
        cerr << "Usage: <./Harl> " << endl;
        return (1);
    }
    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");
    return (0);
}