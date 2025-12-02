/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:07:45 by gbodur            #+#    #+#             */
/*   Updated: 2025/12/02 14:23:28 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

using   std::cout;
using   std::endl;

void    Zombie::setZombieHorde(string name)
{
    this->name = name;
}

Zombie::Zombie()
{
}
Zombie::~Zombie(void)
{
    cout << "Zombie " << this->name << " has gone" << endl;
}

void    Zombie::announce(void)
{
    cout << this->name << ": " "BraiiiiiiinnnzzzZ..." << endl; 
}