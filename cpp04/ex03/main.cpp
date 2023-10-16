/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:33:40 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/16 17:35:49 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Character.hpp"
#include "List.hpp"
void aaa(void)
{
	system("leaks -q run");
}

int main(void)
{
	atexit(aaa);
	
	List* a = new List();

	a->addNodeBack(new Ice());
	a->addNodeBack(new Ice());
	a->addNodeBack(new Ice());

	delete a;
	return 0;
}