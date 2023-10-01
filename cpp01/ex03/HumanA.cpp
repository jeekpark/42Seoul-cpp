/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:14:27 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/01 14:55:28 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon ) : _name(name), _weapon(weapon)
{
	std::cout
		<< "[HumanA constructed]\tname:\t"
		<< name
		<< ",\tweapon: "
		<< weapon.getType()
		<< std::endl;
}

HumanA::~HumanA( void )
{
	std::cout
		<< "[HumanA destructed]\tname:\t"
		<< this->_name
		<< ",\tweapon: "
		<< this->_weapon.getType()
		<< std::endl;
}

void	HumanA::attack( void ) const
{
	std::cout
		<< this->_name
		<< " attacks with his "
		<< this->_weapon.getType()
		<< std::endl;
}