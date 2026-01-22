/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 20:36:48 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/22 21:24:29 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

using std::cout;
using std::endl;

ClapTrap::ClapTrap() : _name(""), _hitPoints(100), _energyPoints(100), _attackDamage(30)
{
	cout << "ClapTrap default constructor called" << endl;
}

ClapTrap::ClapTrap(const string &name) : _name(name), _hitPoints(100), _energyPoints(100), _attackDamage(30)
{
	cout << "ClapTrap " << this->_name << " constructor called" << endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
	this->_name = clapTrap._name;
	this->_hitPoints = clapTrap._hitPoints;
	this->_attackDamage = clapTrap._attackDamage;
	this->_energyPoints = clapTrap._energyPoints;
	cout << "ClapTrap " << this->_name << " copy constructor called" << endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap)
{
	cout << "ClapTrap " << this->_name << " copy assignment operator called" << endl;
	if (this != &clapTrap)
	{
		this->_name = clapTrap._name;
		this->_attackDamage = clapTrap._attackDamage;
		this->_energyPoints = clapTrap._energyPoints;
		this->_hitPoints = clapTrap._hitPoints;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	cout << "ClapTrap " << this->_name << " destructor called" << endl;
}

void ClapTrap::attack(const string &target)
{
	cout << "> Energy point for " << this->_name << ": " << this->_energyPoints
		<< " | Hit point for " << this->_name << ": " << this->_hitPoints << endl;
	if (this->_hitPoints == 0)
	{
		cout << "ClapTrap " << this->_name << " can't attack, no hit points left!" << endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		cout << "ClapTrap " << this->_name << " can't attack, no energy points left!" << endl;
		return ;
	}
	else if(this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		cout << "ClapTrap " << this->_name
			<< " attacks " << target << ", causing "
			<< this->_attackDamage << " points of damage. " << endl;
		this->_energyPoints--;
		cout << "> Energy point for " << this->_name << ": " << this->_energyPoints << endl;
		cout << endl;
	}
	else
        cout << "ClapTrap has gone." << endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	cout << "> Energy point for " << this->_name << ": " << this->_energyPoints
		<< " | Hit point for " << this->_name << ": " << this->_hitPoints << endl;
	if (amount >= this->_hitPoints)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	cout << "ClapTrap " << this->_name
		<< " takes " << amount << " points of damage!" << " Hit point for " << this->_name
		<< ": " << this->_hitPoints << endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		cout << "ClapTrap " << this->_name << " can't be repaired, no hit points left!" << endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		cout << "ClapTrap " << this->_name << " can't be repaired, no energy points left!" << endl;
		return ;
	}
	cout << "ClapTrap " << this->_name
		<< " repairs itself, recovering " << amount << " hit points! " << endl;
	this->_energyPoints--;
	cout << "> Energy point for " << this->_name << ": " << this->_energyPoints << " | ";
	this->_hitPoints += amount;
	cout << "Hit point for " << this->_name << ": " << this->_hitPoints << endl;
}

unsigned int ClapTrap::getAttackDamage() const
{
	return(this->_attackDamage);
}
