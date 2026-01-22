/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 20:37:24 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/22 19:58:17 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		string _name;
	public:
		DiamondTrap();
		DiamondTrap(const string &name);
		DiamondTrap(const DiamondTrap &diamondTrap);
		DiamondTrap &operator=(const DiamondTrap &diamondTrap);
		~DiamondTrap();
		void attack(const std::string &target);
    	void whoAmI();
};

#endif