/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:44:27 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/19 13:29:06 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <vector>

#include "./BitcoinDatabase.hpp"

class BitcoinExchange
{
public:
                                  BitcoinExchange(void);
                                  BitcoinExchange(const BitcoinExchange& copy);
                                  ~BitcoinExchange(void);
  BitcoinExchange&                operator=(const BitcoinExchange& copy);

  void                            importDatabase(const std::string& databaseFilePath);
  void                            exchange(const std::string& inputFilePath);
  const std::vector<std::string>& getExchangeResult(void) const;

  class InvalidInputException	: public std::exception
  { public: virtual const char* what(void) const throw(); };
  class EmptyDatabaseException : public std::exception
  { public: virtual const char* what(void) const throw(); };
private:
  BitcoinDatabase                 mDatabase;
  std::vector<std::string>        mExchangeResult;
  
  void                            resetPreviousDate(std::string& date);
};

#endif