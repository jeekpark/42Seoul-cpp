/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:06:59 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/13 20:14:21 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./split.hpp"

#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> split(const std::string& str, char c)
{
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(str);

	while (std::getline(tokenStream, token, c))
	{
		tokens.push_back(token);
	}
	return tokens;
}
