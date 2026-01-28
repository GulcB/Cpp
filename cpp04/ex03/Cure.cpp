/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:09:24 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/28 19:18:55 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

using std::cout;
using std::endl;

Cure::Cure() : AMateria("cure")
{

}

Cure::Cure(const Cure &src) : AMateria(src)
{

}

Cure &Cure::operator=(const Cure &src)
{
    if (this != &src)
    {
        AMateria::operator=(src);
    }
    return (*this);
}

Cure::~Cure()
{

}

AMateria* Cure::clone() const
{
    return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
    cout << "* heals " << target.getName() << "'s wounds *" << endl;
}
