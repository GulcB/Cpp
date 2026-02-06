/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:23:16 by gbodur            #+#    #+#             */
/*   Updated: 2026/02/06 09:45:13 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() 
	: AForm("Presidential Pardon Form", 25, 5), _target("Default")
{
	cout << "PresidentialPardonForm default constructor called" << endl;
}

PresidentialPardonForm::PresidentialPardonForm(const string &target) 
	: AForm("Presidential Pardon Form", 25, 5), _target(target)
{
	cout << "PresidentialPardonForm " << this->_target << " constructor called" << endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) 
	: AForm(other), _target(other._target)
{
	cout << "PresidentialPardonForm copy constructor called" << endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	cout << "PresidentialPardonForm copy assignment operator called" << endl;
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	cout << "PresidentialPardonForm destructor called" << endl;
}

void PresidentialPardonForm::action() const
{
	cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << endl;
}
