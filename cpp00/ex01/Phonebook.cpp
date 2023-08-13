/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 13:41:23 by jeekpark          #+#    #+#             */
/*   Updated: 2023/08/13 19:16:41 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook()
{
	this->_index = 0;
	this->_count = 0;
}

Phonebook::~Phonebook()
{}

void	Phonebook::add()
{
	std::string	str;

	std::cout << "First name: ";
	std::getline(std::cin, str);
	this->_contacts[this->_index].set_first_name(str);

	std::cout << "Last name: ";
	std::getline(std::cin, str);
	this->_contacts[this->_index].set_last_name(str);

	std::cout << "Nickname: ";
	std::getline(std::cin, str);
	this->_contacts[this->_index].set_nick_name(str);

	std::cout << "Phone number: ";
	std::getline(std::cin, str);
	this->_contacts[this->_index].set_phone_number(str);

	std::cout << "Darkest secret: ";
	std::getline(std::cin, str);
	this->_contacts[this->_index].set_darkest_secret(str);
	
	if (this->_count != 8)
		this->_count++;
	this->_index++;
	if (this->_index == 8)
		this->_index = 0;
}

void	Phonebook::_print_value(std::string str)
{
	int	str_len = str.length();
	for (int i = 0; i < 10 - str_len; i++)
		std::cout << " ";
	if (str_len <= 10)
		std::cout << str;
	else
		std::cout << str.substr(0, 9) << '.';
	std::cout << "│";
}

void	Phonebook::_print_contact(int index)
{
	std::cout << "│         " << index << "│";
	this->_print_value(this->_contacts[index].get_first_name());
	this->_print_value(this->_contacts[index].get_last_name());
	this->_print_value(this->_contacts[index].get_nick_name());
	std::cout << "\n";
}

void	Phonebook::search()
{
	std::cout
		<< "┌──────────┬──────────┬──────────┬──────────┐\n"
		<< "│     Index│First name│ Last name│  Nickname│\n"
		<< "├──────────┼──────────┼──────────┼──────────┤\n";
	if (this->_count == 0)
		std::cout
			<< "│         -│         -│         -│         -│\n"
			<< "└──────────┴──────────┴──────────┴──────────┘\n";
	else
	{
		for (int i = 0; i < this->_count; i++)
		{
			this->_print_contact(i);
			if (i + 1 != this->_count)
				std::cout
					<< "├──────────┼──────────┼──────────┼──────────┤\n";
		}
		std::cout
			<< "└──────────┴──────────┴──────────┴──────────┘\n";
	}
}