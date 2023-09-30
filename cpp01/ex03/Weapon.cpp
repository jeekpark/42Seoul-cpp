/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:21:28 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/30 18:35:40 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type ) : _type(type)
{
	std::cout << "[Constructed] type: " << this->_type << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "[Destructed ] type: " << this->_type << std::endl;
}

const std::string&	Weapon::getType( void ) const
{
	return this->_type;
}

void	Weapon::setType( std::string type )
{
	this->_type = type;
}