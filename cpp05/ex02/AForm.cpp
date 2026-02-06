/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 15:57:03 by gbodur            #+#    #+#             */
/*   Updated: 2026/02/06 09:41:06 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
	cout << "AForm default constructor called" << endl;
}

AForm::AForm(const string &name, int gradeToSign, int gradeToExecute) 
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	cout << "AForm " << this->_name << " constructor called" << endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other) 
	: _name(other._name), _isSigned(other._isSigned), 
	  _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	cout << "AForm copy constructor called" << endl;
}

AForm &AForm::operator=(const AForm &other)
{
	cout << "AForm copy assignment operator called" << endl;
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return (*this);
}

AForm::~AForm()
{
	cout << "AForm " << this->_name << " destructor called" << endl;
}

const string &AForm::getName() const { return (this->_name); }
bool AForm::getIsSigned() const { return (this->_isSigned); }
int AForm::getGradeToSign() const { return (this->_gradeToSign); }
int AForm::getGradeToExecute() const { return (this->_gradeToExecute); }

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	this->_isSigned = true;
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (!this->_isSigned)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->_gradeToExecute)
		throw AForm::GradeTooLowException();
	this->action();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed!");
}

ostream &operator<<(ostream &o, const AForm &f)
{
	o << "AForm: " << f.getName() << ", Signed: ";
	if (f.getIsSigned())
		o << "Yes";
	else
		o << "No";
	o << ", Grade to sign: " << f.getGradeToSign()
	  << ", Grade to execute: " << f.getGradeToExecute();
	return (o);
}
