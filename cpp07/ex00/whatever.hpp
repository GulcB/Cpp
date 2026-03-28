/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:52:50 by gbodur            #+#    #+#             */
/*   Updated: 2026/03/27 17:52:51 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T &left, T &right)
{
	T temp;

	temp = left;
	left = right;
	right = temp;
}

template <typename T>
const T &min(const T &left, const T &right)
{
	if (left < right)
		return (left);
	return (right);
}

template <typename T>
const T &max(const T &left, const T &right)
{
	if (left > right)
		return (left);
	return (right);
}

#endif
