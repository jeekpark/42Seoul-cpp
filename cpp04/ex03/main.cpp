/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:33:40 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/17 00:02:13 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Character.hpp"

void aaa(void)
{
	system("leaks -q run");
}

int main(void)
{
	atexit(aaa);
	
	Character* me = new Character("me");
	Character* target = new Character("police");
	AMateria* tmp = new Ice();

	me->equip(tmp);
	me->use(0, *target);
	
	me->unequip(0);
	me->use(0, *target);
	
	delete me;
	delete target;


	std::cout << "\n\n" << std::endl;
	return 0;
}