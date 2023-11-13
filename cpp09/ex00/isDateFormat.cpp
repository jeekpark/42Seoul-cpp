/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isDateFormat.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:41:47 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/13 20:44:35 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./isDateFormat.hpp"
#include <cctype>
#include <cstddef>

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
	return true;
}