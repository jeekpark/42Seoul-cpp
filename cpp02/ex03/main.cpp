/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:25:03 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/07 17:11:42 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main( void )
{
	if ( bsp( Point( 0.0f, 0.0f ), Point( 0.0f, 0.0f ),
					Point( 0.0f, 10.0f ), Point( 0.0f, 0.0f ) ) == true)
		std::cout << "true" << std::endl;
	else
		std::cout << "fasle" << std::endl;

	return 0;
}