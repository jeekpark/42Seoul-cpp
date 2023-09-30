/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 23:57:43 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/30 16:44:19 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	this->_name = "";
	std::cout << "[Constructed] name: <null>" << std::endl;
}

Zombie::Zombie( std::string name )
{
	this->_name = name;
	std::cout << "[Constructed] name: " << name << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "[Destructed] name: " << this->_name << std::endl;
}

void	Zombie::announce( void ) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName( std::string name )
{
	this->_name = name;
	std::cout << "This zombie got name, " << name << std::endl; 
}