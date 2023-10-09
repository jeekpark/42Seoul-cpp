/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:25:59 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/09 21:21:11 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap	temp("Bob");
	DiamondTrap bob = temp;
	std::cout << std::endl;

	bob.printStatus();
	std::cout << std::endl;

	bob.whoAmI();
	std::cout << std::endl;

	bob.attack("you");
	std::cout << std::endl;

	return 0;
}