/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:25:03 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/05 17:02:12 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main( void )
{
	bool a = bsp( Point( 0.0f, 0.0f ), Point( 1.0f, 0.0f ), 
					Point( 0.0f, 1.0f ), Point( 10.0f, 10.0f ) );
	if ( a == true ) std::cout << "true" << std::endl;
	
	return 0;
}