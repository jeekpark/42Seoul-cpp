/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:25:59 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/09 16:56:33 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap	bob("Bob");
	std::cout << std::endl;


	bob.attack("Pawn");
	bob.guardGate();
	std::cout << std::endl;


	ClapTrap*	ptr = &bob;
	ptr->attack("Queen");
	std::cout << std::endl;

	bob.takeDamage(95);
	bob.takeDamage(5);
	bob.takeDamage(3);
	bob.beRepaired(100);
	std::cout << std::endl;
	return 0;
}