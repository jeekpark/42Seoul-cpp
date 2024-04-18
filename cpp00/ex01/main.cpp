/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 12:08:16 by jeekpark          #+#    #+#             */
/*   Updated: 2024/04/18 21:01:28 by jeekpark         ###   ########.fr       */
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
		{
			my_phone_book.show_contacts();
			std::cout << "Index: ";
			std::getline(std::cin, cmd);
			if (cmd.size() == 1 && ('0' <= cmd[0] && cmd[0] <= '9'))
			{
				my_phone_book.show_contact_by_index(cmd[0] - '0');
			}
			else
			{
				std::cout << "Wrong format." << std::endl;
			}
		}
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (0);
		}
	}
	return (0);
}
