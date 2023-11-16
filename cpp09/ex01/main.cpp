/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 23:14:14 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/16 23:48:13 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <exception>
#include <iostream>
#include "RPN.hpp"

static void insertElementsString(char* argv, RPN& rpn)
{
	for (std::size_t i = 0; argv[i]; ++i)
	{
		if (i % 2 == 0 && argv[i] != ' ')
			rpn.insert(argv[i]);
		else if (i % 2 == 1 && argv[i] == ' ')
			continue;
		else
			throw RPN::IncompleteExpressionException();
	}
}

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Error" << std::endl;
		return 1;
	}
	RPN rpn;
	try
	{
		insertElementsString(argv[1], rpn);
		std::cout << rpn.result() << std::endl;
	}
	catch (const std::exception&)
	{
		std::cout << "Error" << std::endl;
	}
	return 0;
}