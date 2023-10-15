/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:58:52 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/15 11:52:18 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("<null>")
{
	std::cout << "Animal default constructed " << _type << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal defalut(type) constructed " << _type << std::endl;
}

Animal::Animal(const Animal& animal)
{
	_type = animal._type;
	std::cout << "Animal copy constructed " << _type << std::endl;
}

Animal&	Animal::operator=(const Animal& animal)
{
	_type = animal._type;
	std::cout << "Animal copy assignment operator " << _type << std::endl;
	return *this;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructed " << _type << std::endl;
}

std::string	Animal::getType(void) const
{
	return _type;
}