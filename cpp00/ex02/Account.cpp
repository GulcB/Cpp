/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:56:00 by gbodur            #+#    #+#             */
/*   Updated: 2025/11/23 18:45:10 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

using   std::time;
using   std::localtime;
using   std::string;
using   std::cout;
using   std::endl;

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
    return (_nbAccounts);
}

int Account::getTotalAmount( void )
{
    return (_totalAmount);
}

int Account::getNbDeposits( void )
{
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals( void )
{
    return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    cout << "accounts:" << _nbAccounts << ";" << \
        "total:" << _totalAmount << ";" << \
        "deposits:" << _totalNbDeposits << ";" << \
        "withdrawals:" << _totalNbWithdrawals << endl;
    
}
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
    int temp_amount = this->_amount;
    
    this->_amount += deposit;
    this->_nbDeposits++;
    
    _totalAmount += deposit;  
    this->_totalNbDeposits++;

    _displayTimestamp();
    cout << "index:" << this->_accountIndex << ";" << \
        "p_amount:" << temp_amount << ";" << \
        "deposit:" << deposit << ";" << \
        "amount:" << this->_amount << ";" << \
        "nb_deposits:" << this->_nbDeposits << endl;
    
}

bool	Account::makeWithdrawal( int withdrawal )
{
    if (this->_amount < withdrawal)
    {
        _displayTimestamp();
        cout << "index:" << this->_accountIndex << ";" << \
            "p_amount:" << this->_amount << ";" << \
            "withdrawal:" << "refused" << endl;
        return (false);
    }
    
    int temp_amount = this->_amount;
    
    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    
    _totalAmount -= withdrawal;
    this->_totalNbWithdrawals++;
    
    _displayTimestamp();
    cout << "index:" << this->_accountIndex << ";" << \
        "p_amount:" << temp_amount << ";" << \
        "withdrawal:" << withdrawal << ";" << \
        "amount:" << this->_amount << ";" << \
        "nb_withdrawals:" << this->_nbWithdrawals << endl;

    return (true);
}

int		Account::checkAmount( void ) const
{
    return (this->_amount);
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    cout << "index:" << this->_accountIndex << ";" << \
        "amount:" << this->_amount << ";"<< \
        "deposits:" << _nbDeposits << ";" << \
        "withdrawals:" << _nbWithdrawals << ";" << endl;
}

Account::~Account( void )
{
    _displayTimestamp();
    cout << "index:" << this->_accountIndex << ";" << "amount:" << this->_amount << ";"<< "closed" << endl;
}

Account::Account( int initial_deposit )
{
    this->_accountIndex = _nbAccounts;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    
    _nbAccounts++;
    _totalAmount += this->_amount;

    _displayTimestamp();
    cout << "index:" << this->_accountIndex << ";" << \
        "amount:" << this->_amount << ";"<< \
        "created" << endl;
}
