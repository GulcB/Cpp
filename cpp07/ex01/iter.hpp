/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:52:59 by gbodur            #+#    #+#             */
/*   Updated: 2026/07/18 16:39:00 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <typename T, typename G>
void iter(T *array, const unsigned int length, G function)
{
	if (!array || !function)
		return ;
	for (unsigned int i = 0; i < length; i++)
	{
        function(array[i]);
	}
}

#endif
