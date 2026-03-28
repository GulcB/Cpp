/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 16:07:29 by gbodur            #+#    #+#             */
/*   Updated: 2026/03/28 12:30:12 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

using std::cout;
using std::endl;
using std::exception;
using std::rand;

Base *generate(void)
{
	int	randomValue;

	randomValue = rand() % 3;
	if (randomValue == 0)
		return (new A());
	if (randomValue == 1)
		return (new B());
	return (new C());
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		cout << "A" << endl;
	else if (dynamic_cast<B *>(p))
		cout << "B" << endl;
	else if (dynamic_cast<C *>(p))
		cout << "C" << endl;
	else
		cout << "Unknown" << endl;
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		cout << "A" << endl;
		return ;
	}
	catch (const exception &)
	{
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		(void)b;
		cout << "B" << endl;
		return ;
	}
	catch (const exception &)
	{
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		cout << "C" << endl;
		return ;
	}
	catch (const exception &)
	{
	}
	cout << "Unknown" << endl;
}
