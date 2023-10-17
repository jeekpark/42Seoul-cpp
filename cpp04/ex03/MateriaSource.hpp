/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:49:39 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/17 10:48:35 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria*		_materias[4];
	public:
						MateriaSource(void);
						MateriaSource(const MateriaSource& copy);
						~MateriaSource(void);
		MateriaSource&	operator=(const MateriaSource& copy);

		void			learnMateria(AMateria*);
		AMateria*		createMateria(const std::string& type);
		AMateria*		getMateriaByIndex(int index) const;
		void			setMateriaByIndex(AMateria* materia, int index);
};

#endif