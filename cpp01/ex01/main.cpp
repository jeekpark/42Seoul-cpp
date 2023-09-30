/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:06:23 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/30 16:55:31 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void )
{
	Zombie	*arr = zombieHorde( 10, "jeekun");

	for ( int i = 0; i < 10; i++ )
	{
		arr[i].announce();
	}
	delete [] arr;
	return 0;
}
