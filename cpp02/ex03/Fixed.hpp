/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:32:07 by gbodur            #+#    #+#             */
/*   Updated: 2025/12/18 15:48:40 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

using   std::ostream;

class Fixed
{
     private:
        int     _fixedPoint;
        static const int   _f_bits;
    public:
        Fixed();
        Fixed(const Fixed &fix);
        ~Fixed();
		Fixed(const int intNum);
        Fixed(const float floatNum);
        float toFloat(void) const;
        Fixed &operator=(const Fixed &fix);
        bool operator>(const Fixed &fix) const;
        bool operator<(const Fixed &fix) const;
        bool operator>=(const Fixed &fix) const;
        bool operator<=(const Fixed &fix) const;
        bool operator==(const Fixed &fix) const;
        bool operator!=(const Fixed &fix) const;
		Fixed operator+(const Fixed &fix) const;
		Fixed operator-(const Fixed &fix) const; 
        Fixed operator*(const Fixed &fix) const;
		Fixed operator/(const Fixed &fix) const;
		Fixed &operator++(void);
		Fixed &operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);
		static Fixed &min(Fixed &first, Fixed &second);
		static const Fixed &min(const Fixed &first, const Fixed &second);
		static Fixed &max(Fixed &first, Fixed &second);
		static const Fixed &max(const Fixed &first, const Fixed &second);
};

ostream & operator<<(ostream & o, Fixed const & i);

#endif