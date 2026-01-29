/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:05:10 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/29 12:16:06 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

using std::cout;
using std::endl;
using std::string;

AMateria::AMateria()
{

}

AMateria::AMateria(string const &type)
{
    this->type = type;
}

AMateria::AMateria(const AMateria &materia)
{
    *this = materia;
}

AMateria &AMateria::operator=(const AMateria &materia)
{
    if (this != &materia)
        this->type = materia.type;
    return (*this);
}

AMateria::~AMateria()
{

}

string const & AMateria::getType() const
{
    return (this->type);
}

void AMateria::use(ICharacter& target)
{
    (void)target;
}
