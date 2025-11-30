/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:50:31 by gbodur            #+#    #+#             */
/*   Updated: 2025/11/30 18:51:34 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <memory>
#include <sstream>

using std::string;

class Zombie
{
    private:
        string name;
    public:
        Zombie();
        ~Zombie(void);
        void announce(void);
        void  setZombieHorde(string name);
};

Zombie* zombieHorde(int N, string name);


#endif