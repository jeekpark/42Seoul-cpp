/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:58:52 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/10 16:13:30 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("<null>")
{
	std::cout << "Animal constructed " << _type << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal constructed " << _type << std::endl;
}

Animal::Animal(const Animal& animal)
{
	_type = animal._type;
	std::cout << "Animal constructed " << _type << std::endl;
}

Animal&	Animal::operator=(const Animal& animal)
{
	_type = animal._type;
	std::cout << "Animal constructed " << _type << std::endl;
	return *this;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructed " << _type << std::endl;
}

void	Animal::makeSound(void) const
{
	std::cout << "ANIMAL!!!! ANIMAL!!!!" << std::endl;
}

std::string	Animal::getType(void) const
{
	return _type;
}