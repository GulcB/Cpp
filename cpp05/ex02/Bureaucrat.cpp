/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:59:55 by gbodur            #+#    #+#             */
/*   Updated: 2026/02/06 09:39:34 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	cout << "Bureaucrat default constructor called" << endl;
}

Bureaucrat::Bureaucrat(const string &name, int grade) : _name(name)
{
	cout << "Bureaucrat " << this->_name << " constructor called" << endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
	cout << "Bureaucrat copy constructor called" << endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	cout << "Bureaucrat copy assignment operator called" << endl;
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	cout << "Bureaucrat " << this->_name << " destructor called" << endl;
}

const string &Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		cout << this->_name << " signed " << form.getName() << endl;
	}
	catch (const exception &e)
	{
		cout << this->_name << " couldn't sign " << form.getName() 
		     << " because " << e.what() << endl;
	}
}

void Bureaucrat::executeForm(const AForm &form)
{
	try
	{
		form.execute(*this);
		cout << this->_name << " executed " << form.getName() << endl;
	}
	catch (const exception &e)
	{
		cout << this->_name << " couldn't execute " << form.getName() 
		     << " because " << e.what() << endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

ostream &operator<<(ostream &o, const Bureaucrat &b)
{
	o << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (o);
}
