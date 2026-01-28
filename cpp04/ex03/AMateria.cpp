/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:05:10 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/28 19:17:41 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

using std::cout;
using std::endl;
using std::string;

AMateria::AMateria()
{

}

AMateria::AMateria(string const & type)
{
    this->type = type;
}

AMateria::AMateria(const AMateria &src)
{
    *this = src;
}

AMateria &AMateria::operator=(const AMateria &src)
{
    if (this != &src)
        this->type = src.type;
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