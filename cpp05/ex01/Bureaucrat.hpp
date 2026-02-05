/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:59:51 by gbodur            #+#    #+#             */
/*   Updated: 2026/02/05 15:28:39 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include <sstream>

using std::string;
using std::cout;
using std::endl;
using std::ostream;
using std::exception;

class Form;

class Bureaucrat
{
	private:
		const string _name;
		int _grade;

	public:
		Bureaucrat();
		Bureaucrat(const string &name, int grade);
		Bureaucrat(const Bureaucrat &bureaucrat);
		Bureaucrat &operator=(const Bureaucrat &bureaucrat);
		~Bureaucrat();

		const string &getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(Form &form);

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
};

ostream &operator<<(ostream &o, const Bureaucrat &b);

#endif
