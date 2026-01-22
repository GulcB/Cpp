/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 20:37:29 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/22 20:00:47 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const string &name);
		FragTrap(const FragTrap &fragTrap);
		FragTrap &operator=(const FragTrap &fragTrap);
		~FragTrap();
		void highFivesGuys(void);
	protected:
		const static unsigned int _hitPoint = 100;
		const static unsigned int _energyPoint = 100;
		const static unsigned int _attackDamega = 30;		
};
#endif