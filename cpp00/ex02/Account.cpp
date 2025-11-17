/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:56:00 by gbodur            #+#    #+#             */
/*   Updated: 2025/11/17 20:48:53 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

using   std::time;
using   std::localtime;
using   std::string;
using   std::cout;

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void )
{
    time_t now = time(NULL);
    
    struct tm *t = localtime(&now);

    char buffer[20];
    strftime(buffer, 20, "[%Y%m%d_%H%M%S] ", t);
    cout << buffer;

}
void	Account::makeDeposit( int deposit )
{
    
}

bool	Account::makeWithdrawal( int withdrawal )
{
    
}

int		Account::checkAmount( void ) const
{
    
}

void	Account::displayStatus( void ) const
{
    
}
    

Account::Account( int initial_deposit )
{
    this->_accountIndex = _nbAccounts;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    
    _nbAccounts++;
    _totalAmount += this->_amount;

    
}