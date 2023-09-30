/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:54:17 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/30 18:06:58 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main( void )
{
	std::string	string("HI THIS IS BRAIN");

	std::string	*stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "string:\t\t" << string << std::endl;
	std::cout << "stringPTR:\t" << stringPTR << std::endl;
	std::cout << "stringREF:\t" << stringREF << std::endl << std::endl;

	std::cout << "&string:\t" << &string << std::endl;
	std::cout << "&stringPTR:\t" << &stringPTR << std::endl;
	std::cout << "&stringREF:\t" << &stringREF << std::endl << std::endl;

	std::cout << "*string:\t<error>" << std::endl;
	std::cout << "*stringPTR:\t" << *stringPTR << std::endl;
	std::cout << "*stringREF:\t<error>" << std::endl;

	return 0;	
}
