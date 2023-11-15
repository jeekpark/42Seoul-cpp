/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinDatabase.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:22:42 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/15 18:35:35 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BITCOINDATABASE_HPP
#define BITCOINDATABASE_HPP

#include <string>
#include <functional>
#include <map>
#include <memory>
#include <utility>
#include <exception>


class BitcoinDatabase
{
public:
	
									BitcoinDatabase(void);
									BitcoinDatabase(const BitcoinDatabase& copy);
									~BitcoinDatabase(void);
	BitcoinDatabase&				operator=(const BitcoinDatabase& copy);

	float							getExchangeRateByDate(const std::string& date) throw(std::exception);
	void							importDatabase(const std::string& databaseFilePath) throw(std::exception);

	class InvaildDatabaseException	: public std::exception
	{ public: virtual const char* what(void) const throw(); };
private:
	typedef std::map<std::string, float, std::less<std::string>,
		std::allocator<std::pair<const std::string, float> > >
									MapT;

	BitcoinDatabase::MapT			mDatabase;

	const BitcoinDatabase::MapT&	getDatabase(void) const;
	void							setDatabase(const BitcoinDatabase::MapT& database);
};

#endif
