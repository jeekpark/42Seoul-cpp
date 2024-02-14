/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:06:59 by jeekpark          #+#    #+#             */
/*   Updated: 2024/02/14 11:43:30 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./split.hpp"

#include <sstream>

std::list<std::string> split(const std::string& str, char c)
{
  std::list<std::string> tokens;
  std::string token;
  std::istringstream tokenStream(str);

  while (std::getline(tokenStream, token, c))
  {
    tokens.push_back(token);
  }
  return tokens;
}
