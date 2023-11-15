/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:44:27 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/15 19:02:17 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <vector>

#include "./BitcoinDatabase.hpp"

class BitcoinExchange {
public:
									BitcoinExchange(void);
									BitcoinExchange(const BitcoinExchange& copy);
									~BitcoinExchange(void);
	BitcoinExchange&				operator=(const BitcoinExchange& copy);

	void							importDatabase(const std::string& databaseFilePath) throw(std::exception);
	void							exchange(const std::string& inputFilePath) throw(std::exception);
	const std::vector<std::string>& getExchangeResult(void) const;

	class InvalidInputException	: public std::exception
	{ public: virtual const char* what(void) const throw(); };
private:
	BitcoinDatabase					mDatabase;
	std::vector<std::string>		mExchangeResult;
};

#endif