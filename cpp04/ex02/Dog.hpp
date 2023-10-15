/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:55:52 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/14 22:21:03 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain*				_brain;
	public:
							Dog(void);
							Dog(const Dog& dog);
							Dog(const Brain& brain);
		Dog&				operator=(const Dog& dog);
							~Dog(void);

		void				makeSound(void) const;
		void				setIdeaByIndex(const std::string& idea, int index);
		const std::string&	getIdeaByIndex(int index) const;
};

#endif