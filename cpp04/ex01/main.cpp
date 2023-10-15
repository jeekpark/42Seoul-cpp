/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:10:21 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/15 11:44:28 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	std::cout << "\n\n\n\n\n" << std::endl;

	Brain* brain = new Brain();
	brain->setIdeaByIndex("hello", 0);

	Cat	cat = Cat(*brain);
	Dog dog = Dog(*brain);
	delete brain;
	std::cout << "\n\n\n" << cat.getIdeaByIndex(0) << std::endl;
	std::cout << dog.getIdeaByIndex(0) << "\n\n\n" << std::endl;

	return 0;
}