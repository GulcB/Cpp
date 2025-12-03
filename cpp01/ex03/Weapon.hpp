/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:24:48 by gbodur            #+#    #+#             */
/*   Updated: 2025/12/03 17:00:23 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

using   std::string;

class Weapon
{
    private:
        string  type;
    public:
        Weapon(string type);
        ~Weapon();
        void    setType(string newType);
        const string   &getType() const;
};

#endif