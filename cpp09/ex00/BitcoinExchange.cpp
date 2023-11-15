/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:45:39 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/15 20:04:39 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./BitcoinExchange.hpp"

#include "./split.hpp"

BitcoinExchange::BitcoinExchange()
: mDatabase()
, mExchangeResult()
{}

BitcoinDatabase::BitcoinExchange(const BitcoinExchange& copy)
: mDatabase(copy.mDatabase)
, mExchangeResult(copy.mExchangeResult)
{}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy)
{
	if (this != &copy)
	{
		mDatabase = copy.mDatabase;
		mExchangeResult = copy.mExchangeResult;
	}
	return *this;
}


void BitcoinExchange::importDatabase(const std::string& databaseFilePath)
{
	mDatabase.importDatabase(databaseFilePath);
}

void BitcoinExchange::exchange(const std::string& inputFilePath)
{
	std::ifstream inputFile(inputFilePath);
	if (inputFile.is_open() == false)
		throw BitcoinExchange::InvalidInputException();
	std::string line;
	if (std::getline(inputFile, line))
	{
		if (line != std::string("date | value"))
			throw BitcoinExchange::InvalidInputException();
	}
	while (std::getline(inputFile, line))
	{
		std::vector<std::string> dateValue = split(line, ' ');
		if (line.length() < 14
			|| line[10] != ' '
			|| line[11] != '|'
			|| line[12] != ' '
			|| dateValue.size() != 3
			|| isDateFormat(dateValue[0]) == false)
		{
			mExchangeResult.push_back(std::string("Error: bad input => ") + line);
			continue;
		}
		long longValue = std::strtol()
		
		
	}
}