/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:16:23 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/10 12:07:43 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	this->_name = "<null>";
	ClapTrap::_name = "<null>_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = 50;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap constructed: <null>" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
	this->_name = name;
	ClapTrap::_name = name + "_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = 50;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap constructed: " << _name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondTrap)
:	ClapTrap(diamondTrap),
	ScavTrap(diamondTrap),
	FragTrap(diamondTrap)
{
	*this = diamondTrap;
	std::cout << "DiamondTrap constructed: " << _name << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& diamondTrap)
{
	this->_name = diamondTrap._name;
	this->_hitPoints = diamondTrap._hitPoints;
	this->_energyPoints = diamondTrap._energyPoints;
	this->_attackDamage = diamondTrap._attackDamage;
	std::cout << "DiamondTrap constructed: " << _name << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructed: " << _name << std::endl;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name:\t" << this->_name
		<< "\nClapTrap name:\t\t" << ClapTrap::_name << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::printStatus(void)
{
	std::cout
		<< "\nname:\t\t" << _name 
		<< "\nhit point:\t" << _hitPoints
		<< "\nenergy point:\t" << _energyPoints
		<< "\nattack damage:\t" << _attackDamage << std::endl << std::endl;
}
