/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:32:11 by gbodur            #+#    #+#             */
/*   Updated: 2025/12/19 17:38:24 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed calc_cp(Point const first, Point const second, Point const point)
{
	Fixed fs_x = second.getX() - first.getX();
	Fixed fs_y = second.getY() - first.getY();

	Fixed fp_x = point.getX() - first.getX();
	Fixed fp_y = point.getY() - first.getY();

	return ((fs_x * fp_y) - (fs_y * fp_x));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed cross_product1 = calc_cp(a, b, point);
	Fixed cross_product2 = calc_cp(b, c, point);
	Fixed cross_product3 = calc_cp(c, a, point);

	if (cross_product1 > 0 && cross_product2 > 0 && cross_product3 > 0)
		return (true);
	
	if (cross_product1 < 0 && cross_product2 < 0 && cross_product3 < 0)
		return (true);

	return (false);
}