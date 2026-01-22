/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:29:21 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/22 12:25:28 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat"; 
	this->brain = new Brain();
    cout << "Cat constructor called" << endl;
}

Cat::Cat(const Cat &brain) : Animal(brain)
{
	this->brain = new Brain(*brain.brain);
	cout << "Cat copy constructor called" << endl;
}

Cat &Cat::operator=(const Cat &brain)
{
	cout << "Cat copy assignment operator called" << endl;
	if (this != &brain)
	{
		Animal::operator=(brain);
		delete this->brain;
		this->brain = new Brain(*brain.brain);
	}
	return (*this);
}

Cat::~Cat()
{
	delete this->brain;
	cout << "Cat destructor called" << endl;
}

void Cat::makeSound() const
{
	cout << "MEOOOOOOOOWWWWWWWW!" << endl;
}

