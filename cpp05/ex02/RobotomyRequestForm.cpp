/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:21:16 by gbodur            #+#    #+#             */
/*   Updated: 2026/02/06 09:44:35 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
	: AForm("Robotomy Request Form", 72, 45), _target("Default")
{
	cout << "RobotomyRequestForm default constructor called" << endl;
}

RobotomyRequestForm::RobotomyRequestForm(const string &target) 
	: AForm("Robotomy Request Form", 72, 45), _target(target)
{
	cout << "RobotomyRequestForm " << this->_target << " constructor called" << endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) 
	: AForm(other), _target(other._target)
{
	cout << "RobotomyRequestForm copy constructor called" << endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	cout << "RobotomyRequestForm copy assignment operator called" << endl;
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	cout << "RobotomyRequestForm destructor called" << endl;
}

void RobotomyRequestForm::action() const
{
	cout << "* BZZZZZT! DRILLING NOISES *" << endl;
	if (std::rand() % 2 == 0)
		cout << this->_target << " has been robotomized successfully!" << endl;
	else
		cout << "Robotomy failed on " << this->_target << "!" << endl;
}
