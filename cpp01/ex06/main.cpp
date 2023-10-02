/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:10:46 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/02 17:12:53 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main( int argc, char **argv )
{
	if ( argc != 2 )
	{
		std::cerr << "Usage: ./harlFilter <level>" << std::endl;
		return EXIT_FAILURE;
	}
	Harl	harl;

	harl.complain( argv[1] );
	return EXIT_SUCCESS;
}
