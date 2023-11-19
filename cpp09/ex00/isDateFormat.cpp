/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isDateFormat.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:41:47 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/19 13:29:14 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./isDateFormat.hpp"
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <vector>
#include "./split.hpp"


bool isLeapYear(long year)
{
  return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
}

/**
 * @brief Validation YYYY-MM-DD format.
 * 
 * @param str 
 * @return true 
 * @return false 
 */
bool	isDateFormat(const std::string& str)
{
  if (str.length() != 10)
    return false;
  for (std::size_t i = 0; i < 10; ++i)
  {
    if (i == 4 || i == 7)
    {
      if (str[i] != '-') return false;
    }
    else
    {
      if (std::isdigit(str[i]) == false) return false;
    }
  }
  std::vector<std::string> splited = split(str, '-');
  long year = std::strtol(splited[0].c_str(), NULL, 10);
  long month = std::strtol(splited[1].c_str(), NULL, 10);
  long day = std::strtol(splited[2].c_str(), NULL, 10);
  if (!(1 <= month && month <= 12)) return false;
  if (!(1 <= day)) return false;
  const int daysInMonth[12] = {31, isLeapYear(year) ? 29 : 28, 31, 30, 31,30, 31, 31, 30, 31, 30, 31};
  return day <= daysInMonth[month - 1];
}