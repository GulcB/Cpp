/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 20:37:36 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/22 20:00:53 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

using std::string;

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const string &name);
		ScavTrap(const ScavTrap &scavTrap);
		ScavTrap &operator=(const ScavTrap &scavTrap);
		~ScavTrap();
		void attack(const string &target);
		void guardGate();
	protected:
		const static unsigned int _hitPoint = 100;
		const static unsigned int _energyPoint = 50;
		const static unsigned int _attackDamega = 20;
};

#endif