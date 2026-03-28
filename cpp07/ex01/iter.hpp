/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:52:59 by gbodur            #+#    #+#             */
/*   Updated: 2026/03/27 17:53:01 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void iter(T *array, const unsigned int length, void (*function)(T &))
{
	unsigned int	i;

	if (!array || !function)
		return ;
	i = 0;
	while (i < length)
	{
		function(array[i]);
		i++;
	}
}

template <typename T>
void iter(const T *array, const unsigned int length, void (*function)(const T &))
{
	unsigned int	i;

	if (!array || !function)
		return ;
	i = 0;
	while (i < length)
	{
		function(array[i]);
		i++;
	}
}

#endif
