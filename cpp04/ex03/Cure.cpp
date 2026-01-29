/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:09:24 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/29 12:17:32 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

using std::cout;
using std::endl;

Cure::Cure() : AMateria("cure")
{

}

Cure::Cure(const Cure &materia) : AMateria(materia)
{

}

Cure &Cure::operator=(const Cure &materia)
{
    if (this != &materia)
    {
        AMateria::operator=(materia);
    }
    return (*this);
}

Cure::~Cure()
{

}

AMateria *Cure::clone() const
{
    return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
    cout << "* heals " << target.getName() << "'s wounds *" << endl;
}
