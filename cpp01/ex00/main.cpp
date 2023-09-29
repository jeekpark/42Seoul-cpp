/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 23:39:07 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/30 01:22:59 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void )
{
	Zombie	stack1("stack1");
	Zombie	*heap = newZombie("heap");

	stack1.announce();
	heap->announce();
	
	delete heap;

	{
		Zombie	stack2("stack2");
		stack2.announce();
	}
	
	randomChump("stack_random");

	std::cout << "\n\ntime to return\n\n";
	return 0;
}
