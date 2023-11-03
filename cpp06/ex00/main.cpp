/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 23:57:43 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/03 23:52:14 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	ScalarConverter::convert(argv[1]);
	ScalarConverter::printCharType();
	ScalarConverter::printIntType();
	return 0;
}