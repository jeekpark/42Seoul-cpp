/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:17:06 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/14 02:13:10 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <exception>
#include <iostream>

#include "./BitcoinDatabase.hpp"

int main(const int argc, const char** argv)
{
	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return EXIT_FAILURE;
	}
	(void)argv;
	BitcoinDatabase db;
	try
	{
		db.importDatabase("./data.csv");
		std::cout << db.getExchangeRateByDate("2022-013-16");
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return EXIT_FAILURE;
	}


	



	return 0;
}