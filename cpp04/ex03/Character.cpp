/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:51:53 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/15 21:28:09 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
{
	_name = "<null>";
	for (int i = 0; i < 4; ++i)
		setSlotByIndex(NULL, i);
}

Character::Character(const std::string& name)
{
	_name = name;
	for (int i = 0; i < 4; ++i)
		setSlotByIndex(NULL, i);
}

Character::Character(const Character& copy)
{
	_name = copy.getName();
	for (int i = 0; i < 4; ++i)
	{
		AMateria* temp = copy.getSlotByIndex(i);
		if (temp == NULL)
			setSlotByIndex(NULL, i);
		else
			setSlotByIndex(temp->clone(), i);
	}
}

Character::~Character(void)
{
	for (int i = 0; i < 4; ++i)
	{
		AMateria*	temp = getSlotByIndex(i);
		if (temp != NULL)
			delete temp; 
	}
}

Character&	Character::operator=(const Character& copy)
{
	_name = copy.getName();
	for (int i = 0; i < 4; ++i)
	{
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

void	Character::equip(AMateria* m)
{

}

void	Character::unequip(int idx)
{

}

void	Character::use(int idx, ICharacter& target)
{
	
}