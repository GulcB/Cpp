/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 14:53:43 by gbodur            #+#    #+#             */
/*   Updated: 2025/11/29 19:03:42 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

using   std::cout;
using   std::cin;
using   std::endl;

int main(int argc, char **argv)
{
    Zombie  *given_name;
    string		command;

    if (argc != 2)
        return (1);
    while(true)
    {
        cout << "Please, enter the zombie name: ";
        getlinecin >> command;
        
    }
    
    return (0);
}