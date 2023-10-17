/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:39:02 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/17 11:14:57 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; ++i)
	{
		setMateriaByIndex(NULL, i);
	}
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
	for (int i = 0; i < 4; ++i)
	{
		AMateria* temp = copy.getMateriaByIndex(i);
		if (temp == NULL)
		{
			setMateriaByIndex(NULL, i);
		}
		else
		{
			setMateriaByIndex(temp->clone(), i);
		}
	}
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; ++i)
	{
		AMateria* temp = getMateriaByIndex(i);
		if (temp != NULL)
		{
			delete temp;
		}
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& copy)
{
	for (int i = 0; i < 4; ++i)
	{
		AMateria* temp_this = getMateriaByIndex(i);
		if (temp_this != NULL)
		{
			delete temp_this;
		}
		AMateria* temp_copy = copy.getMateriaByIndex(i);
		if (temp_copy == NULL)
		{
			setMateriaByIndex(NULL, i);
		}
		else
		{
			setMateriaByIndex(temp_copy->clone(), i);
		}
	}
	return *this;
}

void	MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; ++i)
	{
		if (getMateriaByIndex(i) == NULL)
		{
			setMateriaByIndex(m, i);
			return;
		}
	}
	delete m;
}

AMateria*	MateriaSource::createMateria(const std::string& type)
{
	for (int i = 0; i < 4; ++i)
	{
		AMateria* temp = getMateriaByIndex(i);
		if (temp == NULL)
		{
			continue;
		}
		if (temp->getType() == type)
		{
			return temp->clone();
		}
	}
	return (AMateria*)0;
}

AMateria*	MateriaSource::getMateriaByIndex(int index) const
{
	if (0 <= index && index < 4)
	{
		return _materias[index];
	}
	return (AMateria*)0;
}

void	MateriaSource::setMateriaByIndex(AMateria* materia, int index)
{
	if (0 <= index && index < 4)
	{
		_materias[index] = materia;
	}
}