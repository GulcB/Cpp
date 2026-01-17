/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:48:25 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/17 17:16:38 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

using std::cout;
using std::endl;

ClapTrap::ClapTrap() : _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	cout << "ClapTrap default constructor called" << endl;
}

ClapTrap::ClapTrap(const string &name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	cout << "ClapTrap " << this->_name << " constructor called" << endl;
}

ClapTrap::~ClapTrap()
{
	cout << "ClapTrap destructor called" << endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
	this->_name = clapTrap._name;
	this->_hitPoints = clapTrap._hitPoints;
	this->_attackDamage = clapTrap._attackDamage;
	this->_energyPoints = clapTrap._energyPoints;
	cout << "ClapTrap" << this->_name << "copy constructor called" << endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap)
{
	cout << "ClapTrap" << this->_name << "copy assignment operator called" << endl;
	if (this != &clapTrap)
	{
		this->_attackDamage = clapTrap._attackDamage;
		this->_energyPoints = clapTrap._energyPoints;
		this->_hitPoints = clapTrap._hitPoints;
	}
    return (*this);
}

void ClapTrap::attack(const string &target)
{
	cout << "Energy point for " << this->_name << " : " << this->_energyPoints << endl;
 	if (this->_hitPoints == 0 || this->_energyPoints == 0)
	{
		cout << "Energy is not enough" << endl;
		return ;
	}
	else if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		cout << "ClapTrap "<< this->_name
		<< " attacks " << target << ", causing "
		<< this->_attackDamage << " points of damage. ";
		this->_energyPoints--;
		cout << "Energy point for " << this->_name << " : " << this->_energyPoints << endl;
	}
	else
        cout << "ClapTrap has gone." << endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	cout << "Hit point for "  << this->_name << " : " << this->_hitPoints << endl;
	if(amount >= this->_hitPoints)
	{
		this->_hitPoints = 0;
	}
	else if (amount < this->_hitPoints)
	{
        cout << "ClapTrap " << this->_name
		<< " taking damage: " << amount << endl;
        this->_hitPoints -= amount;
		cout << "Hit point for " << this->_name << " : " << this->_hitPoints << endl;
    }
	else
        cout << "ClapTrap already has gone." << endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
	{
        cout << "ClapTrap " << this->_name << " cannot be alive, it has gone." << endl;
		return ;
	}
    if (_energyPoints == 0)
	{
		cout << "ClapTrap " << this->_name << " cannot be alive, it has gone." << endl;
		return ;
	}
	else
		cout << "ClapTrap " << this->_name
		<< " repairing it self adding with "
		<< amount << endl;
	this->_energyPoints--;
    this->_hitPoints += amount;
    cout << "New Hit Point for "  << this->_name << " : " << _hitPoints << endl;
}
