/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:24:45 by gbodur            #+#    #+#             */
/*   Updated: 2025/12/03 18:57:41 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

using	std::cout;
using	std::endl;

Weapon::Weapon(string type)
{
	this->type = type;
	cout << "Weapon constructer worked and variable are initialized." << endl;
}

Weapon::~Weapon()
{
	cout << "Weapon destructer worked" << endl;
}

void	Weapon::setType(string type)
{
	this->type = type;
}
const string  &Weapon::getType() const
{
	return(this->type);
}


