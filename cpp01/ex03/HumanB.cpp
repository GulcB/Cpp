/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:24:37 by gbodur            #+#    #+#             */
/*   Updated: 2025/12/03 19:02:15 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

using   std::cout;
using   std::endl;

HumanB::HumanB(string name) : name(name)
{
    this->ptrWeapon = NULL;
    cout << "HumanB constructer worked and pointer are initialized as a null." << endl;
}
void    HumanB::setWeapon(Weapon &ptrWeapon)
{
    this->ptrWeapon = &ptrWeapon;
}

void    HumanB::attack()
{
    if (!this->ptrWeapon)
        cout << this->name << " there is no weapon to attack, so pointer is still null" << endl;
    cout << this->name << " attacks with their " << this->ptrWeapon->getType() << endl;
}
