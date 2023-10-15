/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:01:38 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/15 21:29:11 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string			_name;
		AMateria*			_slot[4];
	public:
							Character(void);
							Character(const Character& copy);
							Character(const std::string& name);
							~Character(void);
		Character&			operator=(const Character& copy);

		AMateria*			getSlotByIndex(int index) const;
		void				setSlotByIndex(AMateria* slot, int index);
		const std::string&	getName(void) const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
};

#endif