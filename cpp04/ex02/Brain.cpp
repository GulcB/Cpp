/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 11:46:40 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/22 11:57:11 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

using std::cout;
using std::endl;

Brain::Brain()
{
	cout << "Barin default constructor called" << endl;
}

Brain::Brain(const Brain &brain)
{
	cout << "Brain copy constructor called" << endl;
	*this = brain;
}

Brain &Brain::operator=(const Brain &brain)
{
	cout << "Copy assignment operator called" << endl;
	if (this != &brain)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = brain.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	cout << "Brain destructor called" << endl;
}
