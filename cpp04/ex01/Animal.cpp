/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:22:21 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/26 12:27:55 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	this->type = "Animal";
	cout << "> " << "Animal constructor called." << endl;
}

Animal::Animal(const Animal &animal)
{
	this->type = animal.type;
	cout << "Animal copy constructor called" << endl;
}

Animal &Animal::operator=(const Animal &animal)
{
	cout << "Animal copy assignment operator called" << endl;
	if (this != &animal)
		this->type = animal.type;
	return (*this);
}

Animal::~Animal()
{
	cout << "> " << "Animal destructor called" << endl;
	cout << endl;
}

void Animal::makeSound() const
{
	cout << "Animal has a sound, monkey's uncle!" << endl;
}

string Animal::getType() const
{
	return(this->type);
}
