/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:50:27 by gbodur            #+#    #+#             */
/*   Updated: 2025/11/30 20:11:40 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

using   std::cout;
using   std::cin;
using   std::getline;
using   std::endl;
using   std::stringstream;

int main(int argc, char **argv)
{
    Zombie  *horde;
    string  command;
    int     zombie_count;
    stringstream    ss;

    zombie_count = 0;
    if (argc != 2)
    {
        cout << "Usage: ./ZombieHorde <How many Zombie should be in horde>";
        return (1);
    }    
    ss << argv[1];
    ss >> zombie_count;
    if (ss.fail())
    {
        cout << "Invalid number!" << endl;
        return (1);
    }
    if (zombie_count <= 0)
    {
        cout << "How can be possible negative number birth to be? No, it's not possible.";
        return (1);
    }
    while(true)
    {
        cout << "Please, enter the zombie name (or 'exit' to quit): ";
        getline(cin, command);
        if (cin.fail())
		{
			cout << "See you another world, goodbye! " << endl;
			break;
		}
        if (command == "exit")
        {
            cout << "Goodbye, old friend ..." << endl;
            break;
        }
        cout << "Zombies have taken over the world" << endl;
        horde = zombieHorde(zombie_count, command);
        for (int i = 0; i < zombie_count; i++)
        {
            horde[i].announce();
            
        }
        delete []horde;
    }
    return (0);
}
