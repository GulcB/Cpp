/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:02:27 by gbodur            #+#    #+#             */
/*   Updated: 2026/02/05 15:28:28 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
	cout << "Form default constructor called" << endl;
}

Form::Form(const string &name, int gradeToSign, int gradeToExecute) 
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	cout << "Form " << this->_name << " constructor called" << endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &form) 
	: _name(form._name), _isSigned(form._isSigned), 
	  _gradeToSign(form._gradeToSign), _gradeToExecute(form._gradeToExecute)
{
	cout << "Form copy constructor called" << endl;
}

Form &Form::operator=(const Form &form)
{
	cout << "Form copy assignment operator called" << endl;
	if (this != &form)
	{
		this->_isSigned = form._isSigned;
	}
	return (*this);
}

Form::~Form()
{
	cout << "Form " << this->_name << " destructor called" << endl;
}

const string &Form::getName() const { return (this->_name); }
bool Form::getIsSigned() const { return (this->_isSigned); }
int Form::getGradeToSign() const { return (this->_gradeToSign); }
int Form::getGradeToExecute() const { return (this->_gradeToExecute); }

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	this->_isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low!");
}

ostream &operator<<(ostream &o, const Form &f)
{
	o << "Form: " << f.getName() 
	  << ", Signed: " << (f.getIsSigned() ? "Yes" : "No")
	  << ", Grade to sign: " << f.getGradeToSign()
	  << ", Grade to execute: " << f.getGradeToExecute();
	return (o);
}
