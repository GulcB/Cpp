/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:42:51 by gbodur            #+#    #+#             */
/*   Updated: 2025/12/20 12:46:46 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

using   std::cout;
using   std::endl;

Harl::Harl()
{
}

Harl::~Harl()
{
}
void    Harl::debug(void)
{
    cout << "DEBUG:\n"
        << "I love having extra bacon for my"
        << "7XL-double-cheese-triple-pickle-special-ketchup burger.\n"
        << "I really do!" << endl;
}

void    Harl::info(void)
{
    cout << "INFO:\n"
        << "I cannot believe adding extra bacon costs more money.\n"
        << "You didn’t put enough bacon in my burger!\n"
        << "If you did, I wouldn’t be asking for more!" << endl;
}

void    Harl::warning(void)
{
    cout << "WARNING:\n"
        << "I think I deserve to have some extra bacon for free.\n"
        << "I’ve been coming for years, whereas you started working here just last month." << endl;
}

void    Harl::error(void)
{
    cout << "ERROR:\n"
        << "This is unacceptable! I want to speak to the manager now." << endl;
}

void    Harl::complain(string level)
{
    string  prompt[4] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };
    
    void (Harl::*ptr[4])(void) = { 
        &Harl::debug, 
        &Harl::info, 
        &Harl::warning, 
        &Harl::error 
    };

    for(int i = 0; i < 4; i++)
    {
        if (prompt[i] == level)
        {
            (this->*ptr[i])(); 
            break;
        }
    }
}