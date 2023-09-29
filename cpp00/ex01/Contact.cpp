/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 21:53:21 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/29 15:50:02 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{}

Contact::~Contact(void)
{}

void	Contact::set_first_name(std::string first_name)
{
	this->_first_name = first_name;
}

void	Contact::set_last_name(std::string last_name)
{
	this->_last_name = last_name;
}

void	Contact::set_nick_name(std::string nick_name)
{
	this->_nick_name = nick_name;
}

void	Contact::set_phone_number(std::string phone_number)
{
	this->_phone_number = phone_number;
}

void	Contact::set_darkest_secret(std::string darkest_secret)
{
	this->_darkest_secret = darkest_secret;
}

std::string	Contact::get_first_name() const
{
	return (this->_first_name);
}

std::string Contact::get_last_name() const
{
	return (this->_last_name);
}

std::string Contact::get_nick_name() const
{
	return (this->_nick_name);
}

std::string Contact::get_phone_number() const
{
	return (this->_phone_number);
}

std::string Contact::get_darkest_secret() const
{
	return (this->_darkest_secret);
}
