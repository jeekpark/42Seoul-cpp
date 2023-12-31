/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:37:34 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/14 17:34:01 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat default constructed " << _type << std::endl;
}

Cat::Cat(const Cat& cat) : Animal(cat)
{
	*this = cat;
	std::cout << "Cat copy constructed " << _type << std::endl;
}

Cat&	Cat::operator=(const Cat& cat)
{
	_type = cat._type;
	std::cout << "Cat copy assignment operator " << _type << std::endl;
	return *this;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructed " << _type << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow!!!! Meow!!!! Meow!!!! Meow!!!!" << std::endl;
}