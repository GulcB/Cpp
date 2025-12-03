/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:24:39 by gbodur            #+#    #+#             */
/*   Updated: 2025/12/03 18:39:18 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

using   std::string;

class HumanB
{
	private:
		Weapon  *ptrWeapon;
		string  name;
	public:
		HumanB(string name);
		void	setWeapon(Weapon &ptrWeapon);
		void	attack();
	
};

#endif