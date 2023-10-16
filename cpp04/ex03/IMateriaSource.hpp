/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:44:55 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/16 15:49:23 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include <string>

class AMateria;
class IMateriaSource
{
	public:
		virtual				~IMateriaSource(void) {}
		virtual void		learnMateria(AMateria*) = 0;
		virtual AMateria*	createMateria(const std::string& type) = 0;
};


#endif