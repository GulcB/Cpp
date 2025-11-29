/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 14:54:00 by gbodur            #+#    #+#             */
/*   Updated: 2025/11/29 18:59:55 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <memory>

using std::string;

class Zombie
{
    private:
        string  name;
        
    public:
        Zombie(string name);
        ~Zombie(void);
        void announce(void);
};
    
Zombie* newZombie(string name);
void randomChump(string name);

#endif