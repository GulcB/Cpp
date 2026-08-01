/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EasyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 09:09:22 by gbodur            #+#    #+#             */
/*   Updated: 2026/08/01 15:31:50 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <vector>
# include <list>
# include <iostream>

using std::find;

template<typename T>
T::iterator EasyFind(T container, int index)
{
	if(container.empty())
		return ;
	for (int i = 0; i < container.size(); i++)
	{
		int search = find(container.begin(), container.end(), index);
		if(search == index)
			return (index);
		else
			
		
	}
}

#endif
