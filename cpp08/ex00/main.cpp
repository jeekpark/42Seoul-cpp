/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:17:06 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/09 19:54:26 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include <vector>
#include "./easyfind.hpp"

int main(void)
{
	{
		std::vector<int> v(10);
		std::vector<int>::iterator it;
		for (std::size_t i = 0; i < 10; ++i)
			v.push_back(i);
		try
		{
			it = easyfind(v, 3);
			std::cout << *it << std::endl;
		}
		catch (const std::exception&)
		{
			std::cout << "easyfind: Can't find." << std::endl;
		}
	}


	{
		std::vector<int> v(10);
		std::vector<int>::iterator it;
		for (std::size_t i = 0; i < 10; ++i)
			v.push_back(i);
		try
		{
			it = easyfind(v, 10);
			std::cout << *it << std::endl;
		}
		catch (const std::exception&)
		{
			std::cout << "easyfind: Can't find." << std::endl;
		}
	}


	return 0;
}