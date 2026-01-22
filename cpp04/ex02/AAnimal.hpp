/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:20:30 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/22 15:21:14 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class AAnimal
{
	protected:
		string type;
	public:
		AAnimal();
		AAnimal(const AAnimal &animal);
		AAnimal &operator=(const AAnimal &aanimal);
		virtual ~AAnimal();
		virtual void makeSound() const = 0;
		string getType() const;
};

#endif
