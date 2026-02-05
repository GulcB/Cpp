/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:59:46 by gbodur            #+#    #+#             */
/*   Updated: 2026/02/05 12:47:18 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

using std::cout;
using std::cerr;
using std::endl;
using std::stringstream;
using std::exception;

int main(int argc, char **argv)
{
	stringstream	ss;
	int	grade;

	if (argc != 3)
	{
		cerr << "Error: Invalid number of arguments." << endl;
		cerr << "Usage: ./bureaucrat <name> <grade>" << endl;
		return (1);
	}
	ss << argv[2];
	ss >> grade;
	if (ss.fail() || !ss.eof())
	{
		cout << "Bureaucrat grade should be pure integer" << endl;
		return (1);
	}
	try
	{
		Bureaucrat bureaucrat(argv[1], grade);
		cout << "---------------------------------" << endl;
		cout << bureaucrat << endl;
		cout << "---------------------------------" << endl;
		cout << "Testing increment..." << endl;
		bureaucrat.incrementGrade();
		cout << bureaucrat << endl;
		cout << "Testing decrement..." << endl;
		bureaucrat.decrementGrade();
		cout << bureaucrat << endl;
	}
	catch (const exception &e)
	{
		cerr << "Exception caught: " << e.what() << endl;
		return (1);
	}
	return (0);
}
