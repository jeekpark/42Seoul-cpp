/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:53:19 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/17 10:56:18 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
}

Cure::Cure(const Cure& copy) : AMateria(copy)
{
}

Cure::~Cure(void)
{
}

Cure&	Cure::operator=(const Cure& copy)
{
	_type = copy.getType();
	return *this;
}

AMateria* Cure::clone(void) const
{
	return new Cure();
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}