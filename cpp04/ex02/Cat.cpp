/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:37:34 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/15 11:35:06 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	_brain = new Brain();
	std::cout << "Cat default constructed " << _type << std::endl;
}

Cat::Cat(const Cat& cat) : Animal(cat)
{
	_brain = new Brain(*cat._brain);
	std::cout << "Cat copy constructed " << _type << std::endl;
}

Cat::Cat(const Brain& brain) : Animal("Cat")
{
	_brain = new Brain(brain);
	std::cout << "Cat default(brain) constructed " << _type << std::endl;
}

Cat&	Cat::operator=(const Cat& cat)
{
	_type = cat._type;
	*_brain = *cat._brain;
	std::cout << "Cat copy assignment operator " << _type << std::endl;
	return *this;
}

Cat::~Cat(void)
{
	delete _brain;
	std::cout << "Cat destructed " << _type << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow!!!! Meow!!!! Meow!!!! Meow!!!!" << std::endl;
}

void	Cat::setIdeaByIndex(const std::string& idea, int index)
{
	_brain->setIdeaByIndex(idea, index);
}

const std::string&	Cat::getIdeaByIndex(int index) const
{
	return _brain->getIdeaByIndex(index);
}