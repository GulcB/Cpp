/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:32:04 by gbodur            #+#    #+#             */
/*   Updated: 2025/12/19 19:15:52 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

using std::cout;
using std::endl;
using std::atof;

int main (int argc, char **argv)
{
	if (argc != 9)
	{
		cout << "Usage: ./bsp <ax> <ay> <bx> <by> <cx> <cy> <px> <py>" << endl;		
		return (1);
	}
	 
	Point a(atof(argv[1]), atof(argv[2]));
	Point b(atof(argv[3]), atof(argv[4]));
	Point c(atof(argv[5]), atof(argv[6]));
	Point p(atof(argv[7]), atof(argv[8]));

	if (bsp(a, b, c, p))
		cout << "True! Point is inside the triangle" << endl;
	else
		cout << "False! Point is outside the triangle, or vertex or on an edge" << endl;
	
	return (0);
}