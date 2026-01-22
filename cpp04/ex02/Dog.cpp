/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:29:37 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/22 15:45:07 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	this->brain = new Brain();
	cout << "Dog constructor called" << endl;
}

Dog::Dog(const Dog &brain) : AAnimal(brain)
{
	this->brain = new Brain(*brain.brain);
	cout << "Dog copy constructor called" << endl;
}

Dog &Dog::operator=(const Dog &brain)
{
	cout << "Dog copy assignment operator called" << endl;
	if (this != &brain)
	{
		AAnimal::operator=(brain);
		delete this->brain;
		this->brain = new Brain(*brain.brain);
	}
	return (*this);
}

Dog::~Dog()
{
	delete this->brain;
	cout << "Dog destructor called" << endl;
}

void Dog::makeSound() const
{
	cout << "HAAAAAAAUUUUVVVV!" << endl;
}

