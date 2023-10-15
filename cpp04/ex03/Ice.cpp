/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:30:15 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/15 16:22:44 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
}

Ice::Ice(const Ice& copy) : AMateria(copy)
{
}

Ice::~Ice(void)
{
}

Ice&	Ice::operator=(const Ice& copy)
{
	_type = copy.getType();
	return *this;
}

AMateria*	Ice::clone(void) const;
{
	return new Ice();
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}