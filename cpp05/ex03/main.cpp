/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:59:46 by gbodur            #+#    #+#             */
/*   Updated: 2026/02/06 12:09:50 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
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

int main(int argc, char **argv)
{
	srand(time(NULL));
	int bGrade;
	
	if (argc != 5)
	{
		cerr << "Error: Invalid arguments." << endl;
		cerr << "Usage: ./bureaucrat <B_Name> <B_Grade> <Form_Name> <Target>" << endl;
		cerr << "Forms: 'shrubbery creation', 'robotomy request', 'presidential pardon'" << endl;
		return (1);
	}
	string bName = argv[1];
	string formName = argv[3];
	string target = argv[4];

	if (!parseArg(argv[2], bGrade))
	{
		cerr << "Error: Bureaucrat grade must be a pure integer." << endl;
		return (1);
	}
	Intern *someRandomIntern = new Intern();
	AForm *rrf = NULL;
	try
	{
		Bureaucrat bureaucrat(bName, bGrade);
		cout << "\n--- BUREAUCRAT ---" << endl;
		cout << bureaucrat << endl;
		cout << "\n--- INTERN WORKING ---" << endl;
		rrf = someRandomIntern->makeForm(formName, target);
		if (rrf)
		{
			cout << "\n--- FORM STATUS ---" << endl;
			cout << *rrf << endl;
			cout << "\n--- PROCESSING ---" << endl;
			bureaucrat.signForm(*rrf);
			bureaucrat.executeForm(*rrf);
		}
	}
	catch (const exception &e)
	{
		cerr << "Exception: " << e.what() << endl;
	}
	if (rrf)
	{
		delete rrf;
		cout << "\nForm deleted." << endl;
	}
	delete someRandomIntern;
	cout << "Intern deleted." << endl;
	return (0);
}
