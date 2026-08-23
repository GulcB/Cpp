/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 09:09:22 by gbodur            #+#    #+#             */
/*   Updated: 2026/08/23 13:29:20 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <stdexcept>
# include <iostream>
# include <string>

template<typename T>
typename T::const_iterator easyfind(const T &container, int index)
{
    typename T::const_iterator it = std::find(container.begin(), container.end(), index);
    if (it == container.end())
        throw std::runtime_error("Container does not have the value.");
    return it;
}

template <typename G>
void runTest(const G &cont, int target, const std::string &containerName)
{
    std::cout << "Testing [" << containerName << "] for value " << target << " -> ";
    try
    {
        typename G::const_iterator it = easyfind(cont, target);
        std::cout << "Success! Iterator points to: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Failed: " << e.what() << std::endl;
    }
}

#endif