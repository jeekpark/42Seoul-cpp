/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:34:50 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/14 17:41:31 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <iostream>

class WrongAnimal
{
	protected:
		std::string		_type;
	public:
						WrongAnimal(void);
						WrongAnimal(std::string type);
						WrongAnimal(const WrongAnimal& wrongAnimal);
		WrongAnimal&	operator=(const WrongAnimal& wrongAnimal);
		virtual			~WrongAnimal(void);

		void			makeSound(void) const;
		std::string		getType(void) const;
};

#endif