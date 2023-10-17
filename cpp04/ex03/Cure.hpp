/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:51:15 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/17 10:53:03 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
					Cure(void);
					Cure(const Cure& copy);
					~Cure(void);
		Cure&		operator=(const Cure& copy);

		AMateria*	clone(void) const;
		void		use(ICharacter& target);
};


#endif