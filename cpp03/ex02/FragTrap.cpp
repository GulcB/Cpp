/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 20:36:53 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/22 17:43:39 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

using std::cout;
using std::endl;

FragTrap::FragTrap() : ClapTrap()
{
	cout << "FragTrap default constructor called." << endl;
}

FragTrap::FragTrap(const string &name) : ClapTrap(name)
{
	cout << "FragTrap " << this->_name << " constructor called." << endl;
}

FragTrap::FragTrap(const FragTrap &fragTrap) : ClapTrap(fragTrap)
{
	cout << "FragTrap " << this->_name << " copy constructor called" << endl;
}

FragTrap &FragTrap::operator=(const FragTrap &fragTrap)
{
	cout << "FragTrap " << this->_name << " copy assignment operator called" << endl;
	if (this != &fragTrap)
	{
		this->_name = fragTrap._name;
		this->_attackDamage = fragTrap._attackDamage;
		this->_energyPoints = fragTrap._energyPoints;
		this->_hitPoints = fragTrap._hitPoints;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	cout << "FragTrap " << this->_name << " destructor called" << endl;
}

void FragTrap::highFivesGuys(void)
{
	cout << "FragTrap " << this->_name << " requests a positive high five!" << endl;
}
