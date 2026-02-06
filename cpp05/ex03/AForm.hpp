/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 15:53:13 by gbodur            #+#    #+#             */
/*   Updated: 2026/02/06 09:40:36 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

using std::string;
using std::cout;
using std::endl;
using std::ostream;
using std::exception;

class Bureaucrat;

class AForm
{
	private:
		const string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;

	public:
		AForm();
		AForm(const string &name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();

		const string &getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(const Bureaucrat &bureaucrat);
		void execute(const Bureaucrat &executor) const;

	protected:
		virtual void action() const = 0;

	public:
		class GradeTooHighException : public exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public exception
		{
			public:
				virtual const char *what() const throw();
		};

		class FormNotSignedException : public exception
		{
			public:
				virtual const char *what() const throw();
		};
};

ostream &operator<<(ostream &o, const AForm &f);

#endif
