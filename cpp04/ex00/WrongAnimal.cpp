/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:22:21 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/20 16:27:10 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "WrongAnimal";
	cout << "WrongAnimal constructor called." << endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal)
{
	this->type = wrongAnimal.type;
	cout << "WrongAnimal copy constructor called" << endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wrongAnimal)
{
	cout << "WrongAnimal copy assignment operator called" << endl;
	if (this != &wrongAnimal)
		this->type = wrongAnimal.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	cout << "WrongAnimal destructor called" << endl;
}

void WrongAnimal::makeSound() const
{
	cout << "WrongAnimal has a sound, christ on a bike!" << endl;
}

string WrongAnimal::getType() const
{
	return(this->type);
}