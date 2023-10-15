/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:33:39 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/14 20:35:25 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructed " << _type << std::endl;
}

WrongCat::WrongCat(const WrongCat& wrongCat) : WrongAnimal(wrongCat)
{
	*this = wrongCat;
	std::cout << "WrongCat copy constructed " << _type << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& wrongCat)
{
	_type = wrongCat._type;
	std::cout << "WrongCat copy assignment operator " << _type << std::endl;
	return *this;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructed " << _type << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Meow!!!! Meow!!!! Meow!!!! Meow!!!!" << std::endl;
}