/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:55:31 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/07 20:39:38 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
	private:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& clapTrap);
		ClapTrap&	operator=(const ClapTrap& clapTrap);
		~ClapTrap(void);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif