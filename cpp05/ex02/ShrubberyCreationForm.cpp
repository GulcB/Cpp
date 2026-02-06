/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:20:32 by gbodur            #+#    #+#             */
/*   Updated: 2026/02/06 09:43:56 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
	: AForm("Shrubbery Creation Form", 145, 137), _target("Default")
{
	cout << "ShrubberyCreationForm default constructor called" << endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const string &target) 
	: AForm("Shrubbery Creation Form", 145, 137), _target(target)
{
	cout << "ShrubberyCreationForm " << this->_target << " constructor called" << endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) 
	: AForm(other), _target(other._target)
{
	cout << "ShrubberyCreationForm copy constructor called" << endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	cout << "ShrubberyCreationForm copy assignment operator called" << endl;
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	cout << "ShrubberyCreationForm destructor called" << endl;
}

void ShrubberyCreationForm::action() const
{
	ofstream outfile((this->_target + "_shrubbery").c_str());
	if (!outfile.is_open())
	{
		cout << "Error opening file" << endl;
		return;
	}
	outfile << "       _-_" << endl;
	outfile << "    /~~   ~~\\" << endl;
	outfile << " /~~         ~~\\" << endl;
	outfile << "{               }" << endl;
	outfile << " \\  _-     -_  /" << endl;
	outfile << "   ~  \\\\ //  ~" << endl;
	outfile << "_- -   | | _- _" << endl;
	outfile << "  _ -  | |   -_" << endl;
	outfile << "      // \\\\" << endl;
	outfile.close();
}