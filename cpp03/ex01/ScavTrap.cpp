/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 20:36:43 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/19 16:38:08 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

using std::cout;
using std::endl;

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_name = "";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	cout << "ScavTrap default constructor called." << endl;
}

ScavTrap::ScavTrap(const string &name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	cout << "ScavTrap " << this->_name << " constructor called." << endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap) : ClapTrap(scavTrap)
{
	this->_name = scavTrap._name;
	this->_hitPoints = scavTrap._hitPoints;
	this->_energyPoints = scavTrap._energyPoints;
	this->_attackDamage = scavTrap._attackDamage;
	cout << "ScavTrap " << this->_name << " copy constructor called" << endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap)
{
	cout << "ScavTrap " << this->_name << " copy assignment operator called" << endl;
	if (this != &scavTrap)
	{
		this->_name = scavTrap._name;
		this->_attackDamage = scavTrap._attackDamage;
		this->_energyPoints = scavTrap._energyPoints;
		this->_hitPoints = scavTrap._hitPoints;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	cout << "ScavTrap " << this->_name << " destructor called" << endl;
}

void ScavTrap::attack(const string &target)
{
	cout << "Energy point for " << this->_name << " : " << this->_energyPoints << endl;
	if (this->_hitPoints == 0)
	{
		cout << "ScavTrap " << this->_name << " can't attack, no hit points left!" << endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		cout << "ScavTrap " << this->_name << " can't attack, no energy points left!" << endl;
		return ;
	}
	else if(this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		cout << "ScavTrap " << this->_name
			<< " attacks " << target << ", causing "
			<< this->_attackDamage << " points of damage. ";
		this->_energyPoints--;
		cout << "Energy point for " << this->_name << " : " << this->_energyPoints << endl;
	}
	else
        cout << "ScavTrap has gone." << endl;
}

void ScavTrap::guardGate()
{
	cout << "ScavTrap is now in Gate keeper mode." << endl;
}