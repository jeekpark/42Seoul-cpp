/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:07:25 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/16 20:25:22 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void)
{
	_type = "<null>";
}
AMateria::AMateria(const std::string& type)
{
	_type = type;
}

AMateria::AMateria(const AMateria& copy)
{
	_type = copy._type;
}

AMateria::~AMateria(void)
{

}

AMateria&	AMateria::operator=(const AMateria& copy)
{
	_type = copy._type;
	return *this;
}

/* member function */

const std::string&	AMateria::getType(void) const
{
	return _type;
}

void	AMateria::use(ICharacter& target)
{
	(void)target;
	std::cout << "This is abstract materia." << std::endl;
}