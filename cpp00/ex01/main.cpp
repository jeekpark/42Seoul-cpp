/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 12:08:16 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/29 15:58:23 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int	main()
{
	std::string	cmd;
	Phonebook 	my_phone_book;

	while (cmd != "EXIT")
	{
		std::cout << "Command: ";
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
			my_phone_book.add();
		else if (cmd == "SEARCH")
			my_phone_book.search();
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (0);
		}
	}
	return (0);
}
