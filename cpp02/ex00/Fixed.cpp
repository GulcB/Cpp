/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 14:25:41 by gbodur            #+#    #+#             */
/*   Updated: 2025/12/07 17:38:25 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

using   std::cout;
using   std::endl;

const int Fixed::_f_bits = 8;

Fixed::Fixed()
{
    cout << "Default constructor called" << endl;
    this->_fixedPoint = 0;
}

Fixed::Fixed(const Fixed &fix)
{
    cout << "Copy constructor called" << endl;
    this->_fixedPoint = fix._fixedPoint;
}

Fixed &Fixed::operator=(const Fixed &fix)
{
    cout << "Copy assignment operator called" << endl;
    if (this != &fix)
        this->_fixedPoint = fix._fixedPoint;
    return (*this);
}

Fixed::~Fixed()
{
    cout << "Destructor called" << endl;
}

int Fixed::getRawBits(void) const
{
    cout << "getRawBits member function called" << endl;
    return(this->_fixedPoint);
}

void    Fixed::setRawBits(int const raw)
{
    this->_fixedPoint = raw;
}