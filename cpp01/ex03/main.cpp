/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:26:06 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/01 14:56:19 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main( void )
{
	{
		Weapon	club = Weapon( "crude spiked club" );
		HumanA	bob( "Bob", club );
		bob.attack();
		club.setType( "some other type of club" );
		bob.attack();
	}
	{
		Weapon	club = Weapon( "crude spiked club" );
		
		HumanB	jim( "Jim" );
		jim.setWeapon(club);
		jim.attack();
		club.setType( "some other type of club" );
		jim.attack();
	}

	return 0;
}