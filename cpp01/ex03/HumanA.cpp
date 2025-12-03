/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:24:26 by gbodur            #+#    #+#             */
/*   Updated: 2025/12/03 18:55:39 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

using   std::cout;
using   std::endl;

HumanA::HumanA(string name, Weapon &refWeapon) : refWeapon(refWeapon), name(name)
{
    cout << "HumanA constructer worked and references are done." << endl;
}

HumanA::~HumanA()
{
    cout << "HumanA destructer worked." << endl;
}

void    HumanA::attack()
{
    cout << this->name << " attacks with their " << this->refWeapon.getType() << endl;
}