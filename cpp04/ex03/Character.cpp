/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:51:53 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/16 15:06:08 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
{
	setName("<null>");
	for (int i = 0; i < 4; ++i)
		setSlotByIndex(NULL, i);
	std::cout << "I AM " << getName() << "!" << std::endl;
}

Character::Character(const std::string& name)
{
	setName(name);
	for (int i = 0; i < 4; ++i)
		setSlotByIndex(NULL, i);
	std::cout << "I AM " << getName() << "!" << std::endl;
}

Character::Character(const Character& copy)
{
	setName(copy.getName());
	for (int i = 0; i < 4; ++i)
	{
		AMateria* temp = copy.getSlotByIndex(i);
		if (temp == NULL)
			setSlotByIndex(NULL, i);
		else
			setSlotByIndex(temp->clone(), i);
	}
	std::cout << "I AM " << getName() << "!" << std::endl;
}

Character::~Character(void)
{
	for (int i = 0; i < 4; ++i)
	{
		delete getSlotByIndex(i);
		setSlotByIndex(NULL, i);
	}
}

Character&	Character::operator=(const Character& copy)
{
	setName(copy.getName());
	for (int i = 0; i < 4; ++i)
	{
		delete getSlotByIndex(i);
		AMateria* temp = copy.getSlotByIndex(i);
		if (temp == NULL) 
			setSlotByIndex(NULL, i);
		else
			setSlotByIndex(temp->clone(), i);
	}
	return *this;
}

AMateria*	Character::getSlotByIndex(int index) const
{
	if (0 <= index && index < 4)
		return _slot[index];
	else
		return NULL;
}

void	Character::setSlotByIndex(AMateria* slot, int index)
{
	if (0 <= index && index < 4)
		_slot[index] = slot;
}

const std::string&	Character::getName(void) const
{
	return _name;
}

void	Character::setName(const std::string& name)
{
	_name = name;
}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; ++i)
		if (getSlotByIndex(i) == NULL)
		{
			setSlotByIndex(m, i);
			return ;
		}
}

void	Character::unequip(int idx)
{
	setSlotByIndex(NULL, idx);
}

void	Character::use(int idx, ICharacter& target)
{
	if (0 <= idx && idx < 4)
	{
		AMateria*	temp = getSlotByIndex(idx);
		if (temp != NULL)
			getSlotByIndex(idx)->use(target);
	}
}