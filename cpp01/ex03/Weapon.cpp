/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:21:28 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/01 14:55:46 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( const std::string type ) : _type(type)
{
	std::cout
		<< "[Weapon constructed]\ttype:\t"
		<< this->_type
		<< std::endl;
}

Weapon::~Weapon()
{
	std::cout
		<< "[Weapon destructed]\ttype:\t"
		<< this->_type
		<< std::endl;
}

const std::string&	Weapon::getType( void ) const
{
	return this->_type;
}

void	Weapon::setType( const std::string type )
{
	this->_type = type;
}