/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 14:19:13 by gbodur            #+#    #+#             */
/*   Updated: 2025/12/07 17:24:18 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
    private:
        int _fixedPoint;
        static const int    _f_bits;
    public:
        Fixed();
        Fixed(const Fixed &fix);
        Fixed &operator=(const Fixed &fix);
        ~Fixed();
        int getRawBits(void) const;
        void    setRawBits(int const raw);
};

#endif