/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:01:38 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/17 09:07:35 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include "Floor.hpp"

class Character : public ICharacter
{
	private:
		std::string			_name;
		AMateria*			_slot[4];
		Floor				_floor;
	public:
							Character(void);
							Character(const Character& copy);
							Character(const std::string& name);
							~Character(void);
		Character&			operator=(const Character& copy);

		const std::string&	getName(void) const;
		void				setName(const std::string& name);

		AMateria*			getSlotByIndex(int index) const;
		void				setSlotByIndex(AMateria* slot, int index);

		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
};

#endif