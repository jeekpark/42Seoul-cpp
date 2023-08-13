/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 19:55:06 by jeekpark          #+#    #+#             */
/*   Updated: 2023/08/12 20:08:00 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; argv[i]; i++)
	{
		std::string	to_print = argv[i];
		for (int j = 0; to_print[j]; j++)
			to_print[j] = std::toupper(to_print[j]);
		std::cout << to_print;
	}
	std::cout << std::endl;
	return (0);
}
