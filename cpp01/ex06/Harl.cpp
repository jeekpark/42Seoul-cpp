/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:46:13 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/02 17:33:55 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void )
{}

Harl::~Harl( void )
{}

void	Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout
		<< "I love having extra bacon for my "
		<< "7XL-double-cheese-triple-pickle-special-"
		<< "ketchup burger.\nI really do!\n"
		<< std::endl;
}

void	Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout
		<< "I cannot believe adding extra bacon costs more money.\n"
		<< "You didn’t put enough bacon in my burger!\n"
		<< "If you did, I wouldn’t be asking for more!\n"
		<< std::endl;
}

void	Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout
		<< "I think I deserve to have some extra bacon for free.\n"
		<< "I’ve been coming for years whereas you started working "
		<< "here since last month.\n"
		<< std::endl;
}

void	Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout
		<< "This is unacceptable, I want to speak to the manager now.\n"
		<< std::endl;
}

void	Harl::complain( std::string level )
{
	
	std::string	levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	int	i = 0;
	for ( ; i < 4; i++ )
		if ( level == levels[i] )
			break;
	switch ( i )
	{
		case 0:
		{
			this->debug();
			__attribute__((fallthrough));
		}
		case 1:
		{
			this->info();
			__attribute__((fallthrough));
		}
		case 2:
		{
			this->warning();
			__attribute__((fallthrough));
		}
		case 3:
		{
			this->error();
			break;
		}
		default:
			std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
