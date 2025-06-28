/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:05:11 by norban            #+#    #+#             */
/*   Updated: 2025/05/14 12:32:11 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void) {
	std::time_t now = std::time(NULL);
	std::tm* local = std::localtime(&now);

	std::cout << "[" << (local->tm_year + 1900)
	          << std::setfill('0') << std::setw(2) << local->tm_mon + 1
	          << std::setw(2) << local->tm_mday << "_"
	          << std::setw(2) << local->tm_hour
	          << std::setw(2) << local->tm_min
	          << std::setw(2) << local->tm_sec
	          << "] ";
	
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
	<< ";total:" << _totalAmount
	<< ";deposits" << _totalNbDeposits
	<< ";withdrawals" << _totalNbWithdrawals
	<< std::endl;
}

Account::Account(int initial_deposit) {
	
	this->_amount = initial_deposit;
	this->_accountIndex = _nbAccounts++;
	_totalAmount += initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index: " << this->_accountIndex
			<< ";amount:" << this->_amount
			<< ";created" << std::endl;
}