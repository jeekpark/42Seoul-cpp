/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:39:02 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/14 17:41:14 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("<null>")
{
	std::cout << "WrongAnimal default constructed " << _type << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "WrongAnimal defalut(type) constructed " << _type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& wrongAnimal)
{
	_type = wrongAnimal._type;
	std::cout << "WrongAnimal copy constructed " << _type << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& wrongAnimal)
{
	_type = wrongAnimal._type;
	std::cout << "WrongAnimal copy assignment operator " << _type << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructed " << _type << std::endl;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal!!!! WrongAnimal!!!!" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return _type;
}