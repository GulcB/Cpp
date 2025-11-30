/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:07:34 by gbodur            #+#    #+#             */
/*   Updated: 2025/11/30 16:18:42 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

using   std::cout;
using   std::endl;

Zombie::Zombie(string name)
{
    this->name = name;
}
Zombie::~Zombie(void)
{
    cout << "Zombie " << this->name << " has gone" << endl;
}
void    Zombie::announce(void)
{
    cout << this->name << ": " "BraiiiiiiinnnzzzZ..." << endl; 
}

