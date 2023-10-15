/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:21:03 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/15 21:18:04 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string			_type;
	public:
							AMateria(void);
							AMateria(const std::string& type);//필수
							AMateria(const AMateria& copy);
		virtual				~AMateria(void);
		AMateria&			operator=(const AMateria& copy);

		const std::string&	getType(void) const;
		virtual AMateria*	clone(void) const  = 0;
		virtual void		use(ICharacter& target);

};

#endif