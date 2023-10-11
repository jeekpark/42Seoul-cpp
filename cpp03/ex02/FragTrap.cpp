/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:34:29 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/09 17:52:49 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	this->_name = "<null>";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout <<  "FragTrap constructed: <null>" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout <<  "FragTrap constructed: " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap& fragTrap) : ClapTrap(fragTrap)
{
	this->_name = fragTrap._name;
	this->_hitPoints = fragTrap._hitPoints;
	this->_energyPoints = fragTrap._energyPoints;
	this->_attackDamage = fragTrap._attackDamage;
	std::cout << "FragTrap Constructed: " << this->_name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& fragTrap)
{
	this->_name = fragTrap._name;
	this->_hitPoints = fragTrap._hitPoints;
	this->_energyPoints = fragTrap._energyPoints;
	this->_attackDamage = fragTrap._attackDamage;
	std::cout << "FragTrap Constructed: " << this->_name << std::endl;
	return *this;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap Destructor: " << this->_name << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
		std::cout << "FragTrap " << this->_name << " positive high five!" << std::endl;
	else
		std::cout << "FragTrap " << this->_name << " can't do anything!" << std::endl;
}
