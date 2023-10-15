/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:19:45 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/15 11:44:37 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	_brain = new Brain();
	std::cout << "Dog default constructed " << _type << std::endl;
}

Dog::Dog(const Dog& dog) : Animal(dog)
{
	_brain = new Brain(*dog._brain);
	std::cout << "Dog copy constructed " << _type << std::endl;
}

Dog::Dog(const Brain& brain) : Animal("Dog")
{
	_brain = new Brain(brain);
	std::cout << "Dog default(brain) constructed " << _type << std::endl;
}

Dog&	Dog::operator=(const Dog& dog)
{
	_type = dog._type;
	*_brain = *dog._brain;
	std::cout << "Dog copy assignment operator " << _type << std::endl;
	return *this;
}

Dog::~Dog(void)
{
	delete _brain;
	std::cout << "Dog destructed " << _type << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Bark!!!! Bark!!!! Bark!!!! Bark!!!!" << std::endl;
}

void	Dog::setIdeaByIndex(const std::string& idea, int index)
{
	_brain->setIdeaByIndex(idea, index);
}

const std::string&	Dog::getIdeaByIndex(int index) const
{
	return _brain->getIdeaByIndex(index);
}