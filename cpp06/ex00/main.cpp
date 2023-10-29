/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 23:57:43 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/29 17:27:41 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{

	ScalarConverter::convert("hllow");
	std::cout << ScalarConverter::getLiteral() << std::endl;
	return 0;
}