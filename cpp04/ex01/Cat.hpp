/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:35:12 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/14 22:22:31 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain*				_brain;
	public:
							Cat(void);
							Cat(const Cat& cat);
							Cat(const Brain& brain);
		Cat&				operator=(const Cat& cat);
							~Cat(void);

		void				makeSound(void) const;
		void				setIdeaByIndex(const std::string& idea, int index);
		const std::string&	getIdeaByIndex(int index) const;
};

#endif