/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:09:02 by gbodur            #+#    #+#             */
/*   Updated: 2025/12/07 18:19:21 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

using   std::cout;
using   std::endl;


ostream & operator<<(ostream & o, Fixed const & i)
{
    o << i.toFloat();
    return o;
}

const int Fixed::_f_bits = 8;

Fixed::Fixed()
{
    cout << "Default constructor called" << endl;
    this->_fixedPoint = 0;
}
Fixed::Fixed(const int intNum)
{
    cout << "Int constructor called" << endl;
    this->_fixedPoint = intNum << this->_f_bits;
}

Fixed::Fixed(const float floatNum)
{
    cout << "Float constructor called" << endl;
    this->_fixedPoint = roundf(floatNum * (1 << this->_f_bits));
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

float   Fixed::toFloat(void) const
{
    return ((float)this->_fixedPoint / ( 1 << this->_f_bits));
}

int Fixed::toInt(void) const
{
   return (this->_fixedPoint >> this->_f_bits);
}