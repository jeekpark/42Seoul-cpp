/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:39:59 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/15 16:22:23 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMetaria
{
	public:
					Ice(void);
					Ice(const Ice& copy);
					~Ice(void);
		Ice&		operator=(const Ice& copy);

		AMateria*	clone(void) const;
		void		use(ICharacter& target);
};

#endif