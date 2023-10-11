/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:34:29 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/09 16:50:29 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	this->_name = "<null>";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout <<  "ScavTrap constructed: <null>" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout <<  "ScavTrap constructed: " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& scavTrap) : ClapTrap(scavTrap)
{
	this->_name = scavTrap._name;
	this->_hitPoints = scavTrap._hitPoints;
	this->_energyPoints = scavTrap._energyPoints;
	this->_attackDamage = scavTrap._attackDamage;
	std::cout << "ScavTrap Constructed: " << this->_name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& scavTrap)
{
	this->_name = scavTrap._name;
	this->_hitPoints = scavTrap._hitPoints;
	this->_energyPoints = scavTrap._energyPoints;
	this->_attackDamage = scavTrap._attackDamage;
	std::cout << "ScavTrap Constructed: " << this->_name << std::endl;
	return *this;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap Destructor: " << this->_name << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
		std::cout << "ScavTrap " << this->_name << " is now in Gatekeeper mode!" << std::endl;
	else
		std::cout << "ScavTrap " << this->_name << " can't do anything!" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target
			<< ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	else
		std::cout << "ScavTrap " << this->_name << " can't do anything!" << std::endl;
}