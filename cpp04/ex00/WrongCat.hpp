/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:41:39 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/14 20:33:27 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
					WrongCat(void);
					WrongCat(const WrongCat& wrongCat);
		WrongCat&	operator=(const WrongCat& wrongCat);
					~WrongCat(void);

		void	makeSound(void) const;
};

#endif