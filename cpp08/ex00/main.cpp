/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 09:09:18 by gbodur            #+#    #+#             */
/*   Updated: 2026/08/01 15:37:14 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EasyFind.hpp"
#include <sstream>

using std::cout;
using std::endl;
using std::cerr;
using std::vector;
using std::list;
using std::stringstream;

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		cerr << "Error: Invalid number of arguments." << endl;
		cerr << "Usage: ./easyfind <numbers in vector> <value>" << endl;
		return (1);
	}
	vector<int> containerVector;
	stringstream ss;
	int values;
	ss << argv[1];
	while (ss >> values)
		containerVector.insert();
	
	
}