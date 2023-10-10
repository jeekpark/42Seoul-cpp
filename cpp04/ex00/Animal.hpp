/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:52:06 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/10 16:12:05 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal
{
	protected:
		std::string		_type;
	public:
						Animal(void);
						Animal(std::string type);
						Animal(const Animal& animal);
		Animal&			operator=(const Animal& animal);
		virtual			~Animal(void);

		virtual void	makeSound(void) const;
		std::string		getType(void) const;
};


#endif