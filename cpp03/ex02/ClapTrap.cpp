/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:08:17 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/09 16:44:28 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	this->_name = "<null>";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "Constructed: <null>" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "Constructed: " << this->_name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap)
{
	this->_name = clapTrap._name;
	this->_hitPoints = clapTrap._hitPoints;
	this->_energyPoints = clapTrap._energyPoints;
	this->_attackDamage = clapTrap._attackDamage;
	std::cout << "Constructed: " << this->_name << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& clapTrap)
{
	this->_name = clapTrap._name;
	this->_hitPoints = clapTrap._hitPoints;
	this->_energyPoints = clapTrap._energyPoints;
	this->_attackDamage = clapTrap._attackDamage;
	std::cout << "Constructed: " << this->_name << std::endl;
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor: " << this->_name << std::endl;
}
void	ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target
			<< ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	else
		std::cout << "ClapTrap " << this->_name << " can't do anything!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > this->_hitPoints)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	std::cout << "ClapTrap " << this->_name << " has taken " << amount
			<< " damages! " << this->_hitPoints << "(HP) left!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		this->_hitPoints += amount;
		this->_energyPoints--;
		std::cout << "ClapTrap " << this->_name << " is repaired, gets "
			<< amount << "(HP)! Now It has " << this->_hitPoints << "(HP)!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " can't do anything!" << std::endl;
}