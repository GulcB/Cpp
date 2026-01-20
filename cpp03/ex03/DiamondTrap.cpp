/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 20:37:22 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/19 21:51:31 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

using std::cout;
using std::endl;

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), ScavTrap(), FragTrap()
{
    this->_name = "";
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
    
    cout << "DiamondTrap default constructor called." << endl;
}

DiamondTrap::DiamondTrap(const string &name) : ClapTrap(name + "_clap_name"),
      ScavTrap(name), 
      FragTrap(name)
{
    this->_name = name;
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
    
    cout << "DiamondTrap " << this->_name << " constructor called." << endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap) : ClapTrap(diamondTrap),
	ScavTrap(diamondTrap), FragTrap(diamondTrap)
{
    this->_name = diamondTrap._name;
	this->_hitPoints = diamondTrap._hitPoints;
    this->_energyPoints = diamondTrap._energyPoints;
    this->_attackDamage = diamondTrap._attackDamage;
	ClapTrap::_name = diamondTrap.ClapTrap::_name;
    cout << "DiamondTrap " << this->_name << " copy constructor called." << endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondTrap)
{
    cout << "DiamondTrap assignment operator called." << endl;
    if (this != &diamondTrap)
    {
		ClapTrap::_name = diamondTrap.ClapTrap::_name;
        this->_name = diamondTrap._name;
        this->_hitPoints = diamondTrap._hitPoints;
        this->_energyPoints = diamondTrap._energyPoints;
        this->_attackDamage = diamondTrap._attackDamage;
    }
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    cout << "DiamondTrap " << this->_name << " destructor called." << endl;
}

void DiamondTrap::attack(const string &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    cout << "I am DiamondTrap " << this->_name 
         << " and my ClapTrap name is " << ClapTrap::_name << endl;
}
