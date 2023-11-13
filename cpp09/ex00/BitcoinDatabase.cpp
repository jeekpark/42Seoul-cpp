/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinDatabase.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:05:43 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/14 02:08:42 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./BitcoinDatabase.hpp"

#include <cstddef>
#include <exception>
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <utility>
#include <vector>

#include "./split.hpp"
#include "./isDateFormat.hpp"

/* public head */
BitcoinDatabase::BitcoinDatabase(void) {}

BitcoinDatabase::BitcoinDatabase(const BitcoinDatabase& copy)
: mDatabase(copy.getDatabase()) {}

BitcoinDatabase::~BitcoinDatabase(void) {}

BitcoinDatabase& BitcoinDatabase::operator=(const BitcoinDatabase& copy)
{
	if (this != &copy)
		setDatabase(copy.getDatabase());
	return *this;
}

float BitcoinDatabase::getExchangeRateByDate(const std::string& date) throw(std::exception)
{
	return getDatabase().at(date);
}

void BitcoinDatabase::importDatabase(const std::string& databaseFilePath) throw(std::exception)
{
	mDatabase.clear();
	std::ifstream inputFile(databaseFilePath);
	if (inputFile.is_open() == false)
		throw BitcoinDatabase::InvaildDatabaseException();
	std::string line;
	if (std::getline(inputFile, line))
	{
		if (line != std::string("date,exchange_rate"))
			throw BitcoinDatabase::InvaildDatabaseException();
	}
	while (std::getline(inputFile, line))
	{
		std::vector<std::string> dateRate = split(line, ',');
		if (dateRate.size() != 2)
			throw BitcoinDatabase::InvaildDatabaseException();
		std::string dateLiteral = dateRate[0];
		std::string rateLiteral = dateRate[1];
		char* endPtr = NULL;
		double rate = std::strtod(rateLiteral.c_str(), &endPtr);
		if (isDateFormat(dateLiteral) == false
			|| rateLiteral.length() == 0
			|| *endPtr != '\0'
			|| (-static_cast<double>(std::numeric_limits<float>::max()) <= rate
				&& rate <= static_cast<double>(std::numeric_limits<float>::max())) == false)
			throw BitcoinDatabase::InvaildDatabaseException();
		mDatabase.insert(std::make_pair(dateLiteral, static_cast<float>(rate)));
	}
	if (inputFile.eof())
		inputFile.close();
	else
		throw BitcoinDatabase::InvaildDatabaseException();
}

const char* BitcoinDatabase::InvaildDatabaseException::what(void) const throw()
{
	return "Invalid Database\n";
}
/* public tail */





/* private head */
const BitcoinDatabase::MapT& BitcoinDatabase::getDatabase(void) const
{
	return mDatabase;
}

void BitcoinDatabase::setDatabase(const BitcoinDatabase::MapT& database)
{
	mDatabase = database;
}
/* private tail */

