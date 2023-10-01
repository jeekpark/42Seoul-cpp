/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:19:37 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/01 14:55:30 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : _name(name), _weapon(NULL)
{
	std::cout
		<< "[HumanB constructed]\tname:\t"
		<< this->_name
		<< ",\tweapon: <null>"
		<< std::endl;
}

HumanB::~HumanB( void )
{
	std::cout
		<< "[HumanB Destructed]\tname:\t"
		<< this->_name
		<< ",\tweapon: ";
	if (this->_weapon == NULL)
		std::cout << "<null>" << std::endl;
	else
		std::cout << this->_weapon->getType() << std::endl;
}

void	HumanB::attack( void ) const
{
	std::cout
		<< this->_name
		<< " attacks with their ";
	if (this->_weapon == NULL)
		std::cout << "<null>" << std::endl;
	else
		std::cout << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon( Weapon& weapon )
{
	this->_weapon = &weapon;
}