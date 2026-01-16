/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:48:25 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/16 22:49:47 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

using std::cout;
using std::endl;

ClapTrap::ClapTrap() : _name(""), _hitP(10), _energyP(10), _attackDamage(0)
{
	cout << "ClapTrap default constructor called" << endl;
}

ClapTrap::~ClapTrap()
{
	cout << "ClapTrap destructor called" << endl;
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
		this->_attackDamage = clapTrap._attackDamage;
		this->_energyP = clapTrap._energyP;
		this->_hitP = clapTrap._hitP;
	}
    return (*this);
}

void ClapTrap::attack(const string &target)
{
	if (_hitP == 0 || _energyP == 0)
		cout << "Energy is not enough" << endl;
	else if (_hitP > 0 && _energyP > 0)
	{
		cout << "ClapTrap "<< _name
		<< " attacks " << target << ", causing "
		<< _attackDamage << " points of damage!";
		_energyP--;
	}
	else
        cout << "ClapTrap has gone." << endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if(_hitP > 0)
	{
        cout << "ClapTrap " << _name
		<< " taking damage: " << amount << endl;
        _hitP -= amount;
    }
	else
        cout << "ClapTrap has gone." << endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitP == 0)
	{
        cout << "ClapTrap " << _name << " cannot be alive, it has gone." << endl;
		return ;
	}
    if (_energyP == 0)
	{
		cout << "ClapTrap " << _name << " cannot be alive, it has gone." << endl;
		return ;
	}
	else
		cout << "ClapTrap " << _name
		<< " repairing it self adding with "
		<< amount << endl;
	_energyP--;
    _hitP += amount;
    cout << "New Hit Point is: " << _hitP << endl;
}
