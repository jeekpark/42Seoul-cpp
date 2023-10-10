/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:19:45 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/10 16:13:13 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog constructed " << _type << std::endl;
}

Dog::Dog(const Dog& dog) : Animal(dog)
{
	*this = dog;
	std::cout << "Dog constructed " << _type << std::endl;
}

Dog&	Dog::operator=(const Dog& dog)
{
	_type = dog._type;
	std::cout << "Dog constructed " << _type << std::endl;
	return *this;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructed " << _type << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Bark!!!! Bark!!!! Bark!!!! Bark!!!!" << std::endl;
}