/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:59:46 by gbodur            #+#    #+#             */
/*   Updated: 2026/02/05 15:40:55 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

using std::cout;
using std::cerr;
using std::endl;
using std::stringstream;
using std::exception;

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
	int bGrade;
	int fSignGrade;
	int fExecGrade;

	if (argc != 6)
	{
		cerr << "Error: Invalid number of arguments." << endl;
		cerr << "Usage: ./form <B_Name> <B_Grade> <F_Name> <F_SignGrade> <F_ExecGrade>" << endl;
		return (1);
	}
	if (!parseArg(argv[2], bGrade) || !parseArg(argv[4], fSignGrade) || !parseArg(argv[5], fExecGrade))
	{
		cerr << "Error: Bureaucrat grade and Form grades must be pure integers." << endl;
		return (1);
	}
	try
	{
		Bureaucrat bureaucrat(argv[1], bGrade);
		Form form(argv[3], fSignGrade, fExecGrade);
		cout << "---------------------------------" << endl;
        cout << bureaucrat << endl;
        cout << form << endl;
        cout << "---------------------------------" << endl;
        cout << "Action: " << bureaucrat.getName() << " tries to sign " << form.getName() << "..." << endl;
        bureaucrat.signForm(form);
        cout << "---------------------------------" << endl;
        cout << "Final State: " << endl;
        cout << form << endl;
	}
	catch (const exception &e)
	{
		cerr << "Exception caught: " << e.what() << endl;
		return (1);
	}
	return (0);
}
