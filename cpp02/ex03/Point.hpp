/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:31:39 by gbodur            #+#    #+#             */
/*   Updated: 2025/12/18 16:02:44 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include <string>
#include "Fixed.hpp"

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;	
	public:
		Point();
		Point(const float _pX, const float _pY);
		Point(const Point &point);
		Point &operator=(const Point &point);
		~Point();
};

#endif