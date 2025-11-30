/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:05:55 by gbodur            #+#    #+#             */
/*   Updated: 2025/11/30 16:42:07 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

using   std::cout;
using   std::endl;

Zombie* newZombie(string name)
{
    Zombie *new_one;
    
    new_one = new Zombie(name);
    return (new_one);
}
