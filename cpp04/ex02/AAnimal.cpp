/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:17:52 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/26 14:31:02 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	this->type = "Animal";
	cout << "> " << "Animal constructor called." << endl;
}

AAnimal::AAnimal(const AAnimal &animal)
{
	this->type = animal.type;
	cout << "Animal copy constructor called" << endl;
}

AAnimal &AAnimal::operator=(const AAnimal &animal)
{
	cout << "Animal copy assignment operator called" << endl;
	if (this != &animal)
		this->type = animal.type;
	return (*this);
}

AAnimal::~AAnimal()
{
	cout << "> " << "Animal destructor called" << endl;
	cout << endl;
}

string AAnimal::getType() const
{
	return(this->type);
}
