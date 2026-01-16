/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:48:25 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/16 20:32:53 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

using std::cout;
using std::endl;

ClapTrap::ClapTrap() : _name(_name), _hitP(10), _energyP(10), _attackDamage(0)
{
	cout << "ClapTrap default constructor called" << endl;
}

ClapTrap::~ClapTrap()
{
	cout << "ClapTrap" << _name << "destructor called" << endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
	this->_name = clapTrap._name;
	this->_hitP = clapTrap._hitP;
	this->_attackDamage = clapTrap._attackDamage;
	this->_energyP = this->_energyP;
	cout << "ClapTrap copy constructor called" << endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap)
{
	cout << "ClapTrap" << _name << "copy assignment operator called" << endl;
	if (this != &clapTrap)
	{
        this->_name = clapTrap._name;
		this->_attackDamage = clapTrap._attackDamage;
		this->_energyP = clapTrap._energyP;
		this->_hitP = clapTrap._hitP;
	}
    return (*this);
}

void ClapTrap::attack(const string &target)
{

}

void ClapTrap::takeDamage(unsigned int amount)
{

}

void ClapTrap::beRepaired(unsigned int amount)
{
	
}