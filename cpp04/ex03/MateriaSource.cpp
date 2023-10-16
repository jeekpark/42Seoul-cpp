/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:39:02 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/16 17:00:01 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; ++i)
		setMateriaByIndex(NULL, i);
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
	for (int i = 0; i < 4; ++i)
	{
		AMateria* temp = copy.getMateriaByIndex(i);
		if (temp == NULL)
			setMateriaByIndex(NULL, i);
		else
			setMateriaByIndex(temp->clone(), i);
	}
}

MateriaSource::~MateriaSource(void)
{
	
}