/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:24:32 by gbodur            #+#    #+#             */
/*   Updated: 2025/12/03 17:03:40 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

using   std::string;

class HumanA
{
    private:
        Weapon  &refWeapon;
        string  name;
    public:
        HumanA(string name, Weapon &refWeapon);
        ~HumanA();
        void    attack();
};

#endif