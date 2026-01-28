/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:49:12 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/28 19:05:27 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->type = "WrongCat"; 
    cout << "WrongCat constructor called" << endl;
}

WrongCat::WrongCat(const WrongCat &wrongCat) : WrongAnimal(wrongCat)
{
	this->type = wrongCat.type;
	cout << "WrongCat copy constructor called" << endl;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongCat)
{
	cout << "WrongCat copy assignment operator called" << endl;
	if (this != &wrongCat)
		this->type = wrongCat.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	cout << "WrongCat destructor called" << endl;
}

void WrongCat::makeSound() const
{
	cout << "miew!" << endl;
}

string WrongCat::getType() const
{
	return (this->type);
}