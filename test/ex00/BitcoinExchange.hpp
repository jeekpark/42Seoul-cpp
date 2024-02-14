/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:44:27 by jeekpark          #+#    #+#             */
/*   Updated: 2024/02/14 12:04:43 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <list>
#include <cstdlib>
#include <exception>
#include <fstream>
#include <limits>
#include <sstream>
#include <string>

#include "./split.hpp"
#include "./isDateFormat.hpp"

#include "./BitcoinDatabase.hpp"

class BitcoinExchange
{
public:
  BitcoinExchange(void);
  BitcoinExchange(const BitcoinExchange& copy);
  ~BitcoinExchange(void);
  BitcoinExchange& operator=(const BitcoinExchange& copy);

  void importDatabase(const std::string& databaseFilePath);
  void exchange(const std::string& inputFilePath);
  const std::list<std::string>& getExchangeResult(void) const;

  class InvalidInputException	: public std::exception
  { public: virtual const char* what(void) const throw(); };
  class EmptyDatabaseException : public std::exception
  { public: virtual const char* what(void) const throw(); };
private:
  BitcoinDatabase mDatabase;
  std::list<std::string> mExchangeResult;
  
  void resetPreviousDate(std::string& date);
};

#endif