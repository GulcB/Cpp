/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 14:53:43 by gbodur            #+#    #+#             */
/*   Updated: 2025/12/05 15:49:49 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

using   std::cout;
using   std::cin;
using   std::cerr;
using   std::getline;
using   std::endl;

int main(int argc, char **argv)
{
    Zombie  *given_zombie;
    string  command;

    (void)argv;
    if (argc != 1)
        return (1);
    while(true)
    {
        cout << "Please, enter the zombie name (or 'exit' to quit): ";
        getline(cin, command);
        if (cin.fail())
		{
			cerr << "See you another world, goodbye! " << endl;
			break;
		}
        if (command == "exit")
        {
            cout << "Goodbye, old friend ..." << endl;
            break;
        }
        cout << "newZombie function's written" << endl;
        given_zombie = newZombie(command);
        given_zombie->announce();
        delete given_zombie;
        cout << "randomChump function's written" << endl;
        randomChump(command);
    }
    return (0);
}