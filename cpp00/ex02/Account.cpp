/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:34:57 by jeekpark          #+#    #+#             */
/*   Updated: 2023/08/14 08:00:32 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout
		<< " index:"
		<< this->_accountIndex
		<< ";amount:"
		<< this->_amount
		<< ";created"
		<< std::endl;
}

Account::~Account()
{
	Account::_displayTimestamp();
	std::cout
		<< " index:"
		<< this->_accountIndex
		<< ";amount:"
		<< this->_amount
		<< ";closed"
		<< std::endl;
	Account::_nbAccounts--;
}

void	Account::_displayTimestamp(void)
{
	std::time_t	now = std::time(NULL);
	std::tm		*localTime = std::localtime(&now);

	std::cout
		<< "["
		<< std::setfill('0')
		<< 1900 + localTime->tm_year
		<< std::setw(2) << 1 + localTime->tm_mon
		<< std::setw(2) << localTime->tm_mday
		<< "_"
		<< std::setw(2) << localTime->tm_hour
		<< std::setw(2) << localTime->tm_min
		<< std::setw(2) << localTime->tm_sec
		<< "]";
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout
		<< " index:"
		<< this->_accountIndex
		<< ";amount:"
		<< this->checkAmount()
		<< ";deposits:"
		<< this->_nbDeposits
		<< ";withdrawals:"
		<< this->_nbWithdrawals
		<< std::endl;
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout
		<< " accounts:"
		<< Account::getNbAccounts()
		<< ";total:"
		<< Account::getTotalAmount()
		<< ";deposits:"
		<< Account::getNbDeposits()
		<< ";withdrawals:"
		<< Account::getNbWithdrawals()
		<< std::endl;
}

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

int	Account::checkAmount(void)
{
	return (this->_amount);
}