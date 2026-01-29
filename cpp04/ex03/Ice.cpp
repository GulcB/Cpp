/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:09:31 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/29 12:18:05 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

using std::cout;
using std::endl;

Ice::Ice() : AMateria("ice")
{

}

Ice::Ice(const Ice &materia) : AMateria(materia)
{

}

Ice &Ice::operator=(const Ice &materia)
{
    if (this != &materia)
    {
        AMateria::operator=(materia);
    }
    return (*this);
}

Ice::~Ice()
{

}

AMateria *Ice::clone() const
{
    return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
    cout << "* shoots an ice bolt at " << target.getName() << " *" << endl;
}
