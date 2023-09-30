/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 23:39:20 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/30 16:44:14 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma	once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
	private:
		std::string	_name;
	public:
		Zombie();
		Zombie( std::string name );
		~Zombie( void );
		void	announce( void ) const;
		void	setName( std::string name );

};

Zombie*	zombieHorde( int N, std::string name );

#endif