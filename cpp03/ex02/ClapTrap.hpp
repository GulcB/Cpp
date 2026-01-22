/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 20:36:50 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/22 17:40:34 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <cstring>

using std::string;

class ClapTrap
{
	protected:
		string	_name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;
	public:
		ClapTrap();
		ClapTrap(const string &name);
		virtual ~ClapTrap();
		ClapTrap(const ClapTrap &clapTrap);
		ClapTrap &operator=(const ClapTrap &clapTrap);
		void attack(const string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		unsigned int getAttackDamage() const;
};

#endif