/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:53:42 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/20 16:25:37 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class WrongAnimal
{
	protected:
		string type;
	public:
		WrongAnimal();
		WrongAnimal(const string &type);
		WrongAnimal(const WrongAnimal &wrongAnimal);
		WrongAnimal &operator=(const WrongAnimal &wrongAnimal);
		~WrongAnimal();
		void makeSound() const;
		string getType() const;
};

#endif
