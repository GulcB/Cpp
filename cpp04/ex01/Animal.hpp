/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:22:33 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/26 14:26:51 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <climits>
#include "Cat.hpp"
#include "Dog.hpp"

using std::string;
using std::cout;
using std::endl;

class Animal
{
	protected:
		string type;
	public:
		Animal();
		Animal(const Animal &animal);
		Animal &operator=(const Animal &animal);
		virtual ~Animal();
		virtual void makeSound() const;
		string getType() const;
};

#endif
