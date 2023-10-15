/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:48:04 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/15 10:53:22 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructed" << std::endl;
}

Brain::Brain(const Brain& brain)
{
	*this = brain;
	std::cout << "Brain copy constructed" << std::endl;
}

Brain&	Brain::operator=(const Brain& brain)
{
	for(int i = 0; i < 100; ++i)
		setIdeaByIndex(brain.getIdeaByIndex(i), i);
	std::cout << "Brain copy assignment operator" << std::endl;
	return *this;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructed" << std::endl;
}

void	Brain::setIdeaByIndex(const std::string& idea, int index)
{
	if(0 <= index && index < 100)
		_ideas[index] = idea;
}

const std::string&	Brain::getIdeaByIndex(int index) const
{
	static const std::string	empty;
	if (0 <= index && index < 100)
		return _ideas[index];
	else
		return empty;
}