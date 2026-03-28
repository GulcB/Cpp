/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 16:07:22 by gbodur            #+#    #+#             */
/*   Updated: 2026/03/28 12:30:29 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <exception>

class Base
{
	public:
		virtual ~Base();
};

class A : public Base
{
};

class B : public Base
{
};

class C : public Base
{
};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif
