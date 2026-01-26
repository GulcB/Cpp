/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:29:37 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/26 12:04:44 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	cout << "- " << "Dog constructor called" << endl;
}

Dog::Dog(const Dog &dog) : Animal(dog)
{
	this->type = dog.type;
	cout << "Dog copy constructor called" << endl;
}

Dog &Dog::operator=(const Dog &dog)
{
	cout << "Dog copy assignment operator called" << endl;
	if (this != &dog)
		this->type = dog.type;
	return (*this);
}

Dog::~Dog()
{
	cout << "- " << "Dog destructor called" << endl;
}

void Dog::makeSound() const
{
	cout << "HAAAAAAAUUUUVVVV!" << endl;
}
string Dog::getType() const
{
	return(this->type);
}