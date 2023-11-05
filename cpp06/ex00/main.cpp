/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 23:57:43 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/05 20:34:11 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "usage: ./convert [literal]" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	ScalarConverter::printChar();
	ScalarConverter::printInt();
	ScalarConverter::printFloat();
	ScalarConverter::printDouble();
	return 0;
}