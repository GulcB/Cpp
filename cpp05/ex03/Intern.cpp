/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:57:19 by gbodur            #+#    #+#             */
/*   Updated: 2026/02/06 11:59:17 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	cout << "Intern default constructor called" << endl;
}

Intern::Intern(const Intern &other)
{
	(void)other;
	cout << "Intern copy constructor called" << endl;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	cout << "Intern copy assignment operator called" << endl;
	return (*this);
}

Intern::~Intern()
{
	cout << "Intern destructor called" << endl;
}

AForm *Intern::makeShrubbery(const string &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobotomy(const string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makePresidential(const string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(const string &formName, const string &target)
{
	string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm *(Intern::*funcPtrs[3])(const string &) = {
		&Intern::makeShrubbery,
		&Intern::makeRobotomy,
		&Intern::makePresidential
	};
	for (int i = 0; i < 3; i++)
	{
		if (formNames[i] == formName)
		{
			cout << "Intern creates " << formName << endl;
			return ((this->*funcPtrs[i])(target));
		}
	}
	cout << "Intern cannot create " << formName << " because it doesn't exist." << endl;
	return (NULL);
}
