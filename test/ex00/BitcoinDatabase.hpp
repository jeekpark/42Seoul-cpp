/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinDatabase.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:22:42 by jeekpark          #+#    #+#             */
/*   Updated: 2024/02/14 12:07:42 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BITCOINDATABASE_HPP
#define BITCOINDATABASE_HPP


#include <functional>
#include <map>
#include <memory>
#include <exception>
#include <cstddef>
#include <exception>
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <utility>
#include <cstdlib>

#include "./split.hpp"
#include "./isDateFormat.hpp"

class BitcoinDatabase
{
public:
  
                                BitcoinDatabase(void);
                                BitcoinDatabase(const BitcoinDatabase& copy);
                                ~BitcoinDatabase(void);
  BitcoinDatabase&              operator=(const BitcoinDatabase& copy);

  float                         getExchangeRateByDate(const std::string& date);
  void                          importDatabase(const std::string& databaseFilePath);
  size_t                        getDatabaseSize(void) const;
  
  class InvaildDatabaseException : public std::exception
  { public: virtual const char* what(void) const throw(); };
  class NoPreviousDateFoundException : public std::exception
  { public: virtual const char* what(void) const throw(); };
private:
  typedef std::map<std::string, float, std::less<std::string>,
    std::allocator<std::pair<const std::string, float> > >
                                MapT;

  BitcoinDatabase::MapT         mDatabase;

  const BitcoinDatabase::MapT&  getDatabase(void) const;
  void                          setDatabase(const BitcoinDatabase::MapT& database);
};

#endif
