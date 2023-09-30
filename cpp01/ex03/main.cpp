/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:26:06 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/30 18:38:33 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

int main( void )
{
	Weapon a( "AK47" );

	std::cout << a.getType() << std::endl;

	a.setType( "M4A1" );
	const std::string& str = a.getType();
	std::cout << str << std::endl;

	return 0;
}