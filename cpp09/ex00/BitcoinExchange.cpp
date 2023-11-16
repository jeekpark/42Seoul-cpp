/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:45:39 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/16 18:44:22 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./BitcoinExchange.hpp"

#include <cstdlib>
#include <exception>
#include <fstream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

#include "./split.hpp"
#include "./isDateFormat.hpp"


/* public head */
BitcoinExchange::BitcoinExchange()
: mDatabase()
, mExchangeResult()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
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
	if (mDatabase.getDatabaseSize() == 0)
		throw BitcoinExchange::EmptyDatabaseException();
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
		std::vector<std::string> splited = split(line, ' ');
		if (line.length() < 14
			|| line[10] != ' '
			|| line[11] != '|'
			|| line[12] != ' '
			|| splited.size() != 3
			|| isDateFormat(splited[0]) == false)
		{
			mExchangeResult.push_back(std::string("Error: bad input => ") + line);
			continue;
		}
		std::string date = splited[0];
		std::string bitcoinAmount = splited[2];
		char* endPtr = NULL;
		double bitcoinAmountDouble = std::strtod(bitcoinAmount.c_str(), &endPtr);
		if (*endPtr != '\0')
		{
			mExchangeResult.push_back(std::string("Error: bad input => ") + line);
			continue;
		}
		if (static_cast<double>(std::numeric_limits<int>::max()) < bitcoinAmountDouble)
		{
			mExchangeResult.push_back(std::string("Error: too large a number."));
			continue;
		}
		if (bitcoinAmountDouble < 0.0)
		{
			mExchangeResult.push_back(std::string("Error: not a positive number."));
			continue;
		}
		std::stringstream ss;
		try
		{
			ss << (bitcoinAmountDouble * mDatabase.getExchangeRateByDate(date));		
		}
		catch (const std::exception&)
		{
			mExchangeResult.push_back((std::string("Error: no data.")));
			continue;
		}
		mExchangeResult.push_back(date + std::string(" => ") + bitcoinAmount + std::string(" = ") + ss.str());
	}
}

const std::vector<std::string>& BitcoinExchange::getExchangeResult(void) const
{
	return mExchangeResult;
}

const char* BitcoinExchange::InvalidInputException::what(void) const throw()
{
	return "Invalid input";
}

const char* BitcoinExchange::EmptyDatabaseException::what(void) const throw()
{
	return "Empty database";
}
/* public tail */




/* private head */
void BitcoinExchange::resetPreviousDate(std::string& date)
{
	if (isDateFormat(date) == false) return;
	if (date == std::string("0000-01-01")) return ;
	int year, month, day;
	std::istringstream ss(date);
	ss >> year;
	ss.ignore();
	ss >> month;
	ss.ignore();
	ss >> day;
	if (day > 1)
	{
		--day;
	}
	else
	{
		if (month == 1)
		{
			--year;
			month = 12;
			day = 31;
		}
		else
		{
			month --;
			const int daysInMonth[12] = {31, isLeapYear(year) ? 29 : 28, 31, 30, 31,30, 31, 31, 30, 31, 30, 31};
			day = daysInMonth[month - 1];

		}
	}
	std::ostringstream oss;
	oss << year << "-" << (month < 10 ? "0" : "") << month << "-" << (day < 10 ? "0" : "") << day;
	date = oss.str();
}
/* private tail */