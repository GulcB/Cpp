/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:32:09 by gbodur            #+#    #+#             */
/*   Updated: 2025/12/18 17:08:51 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const  int Fixed::_f_bits = 8;

ostream & operator<<(ostream & o, Fixed const & i)
{
	o << i.toFloat();
	return o;
}

Fixed::Fixed()
{
	this->_fixedPoint = 0;
}

Fixed::Fixed(const Fixed &fix)
{
	this->_fixedPoint = fix._fixedPoint; 
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const int intNum)
{
    this->_fixedPoint = intNum << this->_f_bits;
}

Fixed::Fixed(const float floatNum)
{
    this->_fixedPoint = roundf(floatNum * (1 << this->_f_bits));
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_fixedPoint / (1 << this->_f_bits));	
}

Fixed &Fixed::operator=(const Fixed &fix)
{
	if (this != &fix)
		this->_fixedPoint = fix._fixedPoint;
	return (*this);  
}

bool Fixed::operator>(const Fixed &fix) const
{
	return (this->_fixedPoint > fix._fixedPoint);		
}

bool Fixed::operator<(const Fixed &fix) const
{
	return (this->_fixedPoint < fix._fixedPoint);
}

bool Fixed::operator>=(const Fixed &fix) const
{
	return (this->_fixedPoint >= fix._fixedPoint);
}

bool Fixed::operator<=(const Fixed &fix) const
{
	return (this->_fixedPoint <= fix._fixedPoint);
}

bool Fixed::operator==(const Fixed &fix) const
{
	return (this->_fixedPoint == fix._fixedPoint);
}

bool Fixed::operator!=(const Fixed &fix) const
{
	return (this->_fixedPoint != fix._fixedPoint);
}

Fixed Fixed::operator+(const Fixed &fix) const
{
	return (Fixed(this->toFloat() + fix.toFloat()));
}

Fixed Fixed::operator-(const Fixed &fix) const
{
	return (Fixed(this->toFloat() - fix.toFloat()));	
}

Fixed Fixed::operator*(const Fixed &fix) const
{
	return (Fixed(this->toFloat() * fix.toFloat()));
}

Fixed Fixed::operator/(const Fixed &fix) const
{
	return (Fixed(this->toFloat() / fix.toFloat()));
}

Fixed &Fixed::operator++(void)
{
	this->_fixedPoint =  this->_fixedPoint + 1;
	return (*this);
}

Fixed &Fixed::operator--(void)
{
	this->_fixedPoint =  this->_fixedPoint - 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->_fixedPoint =  this->_fixedPoint + 1;
	return (temp);	
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->_fixedPoint =  this->_fixedPoint - 1;
	return (temp);
}

Fixed &Fixed::min(Fixed &first, Fixed &second)
{
	if (first < second)
		return (first);
	return (second);
}

Fixed const &Fixed::min(const Fixed &first, const Fixed &second)
{
	if (first < second)
		return (first);
	return (second);
}

Fixed &Fixed::max(Fixed &first, Fixed &second)
{
	if (first > second)
		return (first);
	return (second);
}

Fixed const &Fixed::max(const Fixed &first, const Fixed &second)
{
	if (first > second)
		return (first);
	return (second);
}