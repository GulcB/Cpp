/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:42:51 by gbodur            #+#    #+#             */
/*   Updated: 2025/12/05 20:04:41 by gbodur           ###   ########.fr       */
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
    cout << "DEBUG: " << \ 
        "I love having extra bacon for my" << \ 
        "7XL-double-cheese-triple-pickle-specialketchup burger. " << \ 
        "I really do!" << endl;
}

void    Harl::info(void)
{
    cout << "INFO: " << \ 
        "I cannot believe adding extra bacon costs more money. " << \ 
        "You didn’t put enough bacon in my burger! " << \ 
        "If you did, I wouldn’t be asking for more!" << endl;
}

void    Harl::warning(void)
{
    cout << "WARNING: " << \ 
        "I think I deserve to have some extra bacon for free. " << \ 
        "I’ve been coming foryears, whereas you started working here just last month." << endl;
}

void    Harl::error(void)
{
    cout << "ERROR: " << \ 
        "This is unacceptable! I want to speak to the manager now." << endl;
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