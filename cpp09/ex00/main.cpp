/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:17:06 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/19 13:31:35 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>

#include "./BitcoinExchange.hpp"

int main(const int argc, const char** argv)
{
  if (argc != 2)
  {
    std::cout << "Error: could not open file." << std::endl;
    return 1;
  }
  BitcoinExchange exchanger;
  try
  {
    exchanger.importDatabase(std::string("./data.csv"));
    exchanger.exchange(std::string(argv[1]));
    for (std::vector<std::string>::const_iterator it = exchanger.getExchangeResult().begin();
      it != exchanger.getExchangeResult().end(); ++it)
      std::cout << *it << '\n';
  }
  catch (const std::exception& e)
  {
    std::cout << "Error: " << e.what() << std::endl;
    return 1;
  }
  return 0;
}