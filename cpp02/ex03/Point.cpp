/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:31:49 by gbodur            #+#    #+#             */
/*   Updated: 2025/12/19 18:10:08 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
	
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{

}
Point::Point(const Point &point) : _x(point.getX()), _y(point.getY())
{

}

Point &Point::operator=(const Point &point)
{
	(void)point;
	return (*this);
}

Point::~Point()
{
	
}

Fixed Point::getX() const
{
	return (this->_x);
}

Fixed Point::getY() const
{
	return (this->_y);
}