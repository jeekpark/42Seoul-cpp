/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:10:21 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/14 20:38:56 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal*	meta	=	new Animal();
	const Animal*	j 		=	new Dog();
	const Animal*	i 		=	new Cat();
	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << std::endl << std::endl << std::endl;

	const WrongAnimal*	test	=	new WrongAnimal();
	const WrongAnimal*	testCat	=	new WrongCat();

	std::cout << test->getType() << std::endl;
	std::cout << testCat->getType() << std::endl;
	test->makeSound();
	testCat->makeSound();

	delete test;
	delete testCat;

	return 0;
}