/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:31:49 by gbodur            #+#    #+#             */
/*   Updated: 2025/12/18 19:07:03 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(const float _pX, const float _pY)
{
	
}
Point::Point(const Point &point) : _x(0), _y(0)
{	
}
Point &Point::operator=(const Point &point)
{
	if (this != &point)
		this->_x = point._x;
	return (*this);
}

Point::~Point()
{
	
}
