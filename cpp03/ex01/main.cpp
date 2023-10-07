/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:25:59 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/07 20:39:37 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap bob("Bob");
	ClapTrap jim("Jim");

	bob.attack("jim");
	bob.beRepaired(10);
	bob.takeDamage(5);
	bob.takeDamage(20);
	bob.beRepaired(10);
	
	for (int i = 0; i < 12; i++)
		jim.attack("Bob");
	
	return 0;
}