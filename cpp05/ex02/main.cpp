/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:59:46 by gbodur            #+#    #+#             */
/*   Updated: 2026/02/06 09:57:07 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::stringstream;
using std::exception;
using std::srand;
using std::time;

static bool parseArg(char *arg, int &output)
{
	stringstream ss(arg);
	ss >> output;
	if (ss.fail() || !ss.eof())
		return (false);
	return (true);
}

int main(int ac, char **av)
{
	srand(time(NULL));
	int bGrade;
	
	if (ac != 5)
	{
		cerr << "Error: Invalid arguments." << endl;
		cerr << "Usage: ./bureaucrat <B_Name> <B_Grade> <Form_Type> <Target>" << endl;
		cerr << "Form Types: shrubbery, robotomy, presidential" << endl;
		return (1);
	}
	string bName = av[1];
	string formType = av[3];
	string target = av[4];

	if (!parseArg(av[2], bGrade))
	{
		cerr << "Error: Bureaucrat grade must be a pure integer." << endl;
		return (1);
	}
	AForm *form = NULL;
	try
	{
		Bureaucrat bureaucrat(bName, bGrade);
		cout << "\n--- BUREAUCRAT CREATED ---" << endl;
		cout << bureaucrat << endl;
		if (formType == "shrubbery")
			form = new ShrubberyCreationForm(target);
		else if (formType == "robotomy")
			form = new RobotomyRequestForm(target);
		else if (formType == "presidential")
			form = new PresidentialPardonForm(target);
		else
		{
			cerr << "Error: Unknown form type '" << formType << "'." << endl;
			cerr << "Available types: shrubbery, robotomy, presidential" << endl;
			return (1);
		}
		cout << "\n--- FORM CREATED ---" << endl;
		cout << *form << endl;
		cout << "\n--- SIGNING STEP ---" << endl;
		bureaucrat.signForm(*form);
		cout << *form << endl;
		cout << "\n--- EXECUTION STEP ---" << endl;
		bureaucrat.executeForm(*form);
	}
	catch (const exception &e)
	{
		cerr << "\nException caught: " << e.what() << endl;
	}
	if (form)
		delete form;
	return (0);
}
