/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:13:38 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/30 16:42:28 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde( int N, std::string name )
{
	Zombie	*arr = new Zombie[N]();
	for ( int i = 0; i < N; i++ )
		arr[i].setName( name );
	return (arr);
}