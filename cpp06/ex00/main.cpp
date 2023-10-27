/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 23:57:43 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/28 00:21:11 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "error: usage: " << argv[0] << " [literal]." << std::endl;

	return 0;
}