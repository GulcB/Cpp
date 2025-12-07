/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:09:00 by gbodur            #+#    #+#             */
/*   Updated: 2025/12/07 18:19:17 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

using   std::ostream;

class Fixed
{
    private:
        int     _fixedPoint;
        static const int   _f_bits;
    public:
        Fixed();
        Fixed(const int intNum);
        Fixed(const float floatNum);
        Fixed(const Fixed &fix);
        Fixed &operator=(const Fixed &fix);
        ~Fixed();
        float   toFloat(void) const;
        int     toInt(void) const;
        
};

ostream & operator<<(ostream & o, Fixed const & i);
#endif