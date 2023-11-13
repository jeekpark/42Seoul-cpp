/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:44:27 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/14 02:46:50 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include "./BitcoinDatabase.hpp"

class BitcoinExchange {
public:
									BitcoinExchange(void);
									BitcoinExchange(const BitcoinExchange& copy);
									~BitcoinExchange(void);
	BitcoinExchange&				operator=(const BitcoinExchange& copy);

	void							importFile(const std::string& filePath);
	void							importDatabase(const std::string& databaseFilePath);
	void							importDatabase(const BitcoinDatabase& database);
	const std::vector<std::string>&	getResult(void) const;
private:
	BitcoinDatabase					mDatabase;
	std::vector<std::string>		mResult;

};

#endif