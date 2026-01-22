/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:29:21 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/21 16:36:50 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat"; 
    cout << "Cat constructor called" << endl;
}

Cat::Cat(const Cat &cat) : Animal(cat)
{
	this->type = cat.type;
	cout << "Cat copy constructor called" << endl;
}

Cat &Cat::operator=(const Cat &cat)
{
	cout << "Cat copy assignment operator called" << endl;
	if (this != &cat)
		this->type = cat.type;
	return (*this);
}

Cat::~Cat()
{
	cout << "Cat destructor called" << endl;
}

void Cat::makeSound() const
{
	cout << "MEOOOOOOOOWWWWWWWW!" << endl;
}

string Cat::getType() const
{
	return(this->type);
}
