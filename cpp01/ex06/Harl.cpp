/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 11:36:15 by gbodur            #+#    #+#             */
/*   Updated: 2025/12/06 12:18:00 by gbodur           ###   ########.fr       */
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
    cout << "[ DEBUG ]\n"
        << "I love having extra bacon for my"
        << "7XL-double-cheese-triple-pickle-specialketchup burger.\n"
        << "I really do!" << endl;
}

void    Harl::info(void)
{
    cout << "[ INFO ]\n"
        << "I cannot believe adding extra bacon costs more money.\n"
        << "You didn’t put enough bacon in my burger!\n"
        << "If you did, I wouldn’t be asking for more!" << endl;
}

void    Harl::warning(void)
{
    cout << "[ WARNING ]\n"
        << "I think I deserve to have some extra bacon for free.\n" 
        << "I’ve been coming foryears, whereas you started working here just last month." << endl;
}

void    Harl::error(void)
{
    cout << "[ ERROR ]\n"
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
    int i = 0;

    for(i = 0; i < 4; i++)
    {
        if (prompt[i] == level)
            break;
    }
    switch(i)
    {
        case 0:
            this->debug();
        case 1:
            this->info();
        case 2:
            this->warning();
        case 3:
            this->error();
            break;
        default:
            cout << "[ Probably complaining about insignificant problems ]" << endl;
    }
}
