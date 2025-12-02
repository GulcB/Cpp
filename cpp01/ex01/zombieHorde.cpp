/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:02:59 by gbodur            #+#    #+#             */
/*   Updated: 2025/12/02 14:22:36 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

using   std::cout;
using   std::endl;

Zombie* zombieHorde(int N, string name)
{
    Zombie *zombie_army;
    string  new_name;
    
    zombie_army = new Zombie[N];
    cout << "Let's start to introduce the zombies" << endl;
    for(int i = 0; i < N; i++)
    {
        zombie_army[i].setZombieHorde(name);
    }
    return (zombie_army);
}