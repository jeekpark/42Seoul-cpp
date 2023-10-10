/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:25:59 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/10 12:05:40 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap	temp("Bob");

	DiamondTrap	bob = temp ;
	bob.printStatus();

	bob.whoAmI();
	bob.attack("hello");
	return 0;
}