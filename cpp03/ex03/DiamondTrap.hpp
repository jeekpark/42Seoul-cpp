/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:03:25 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/09 21:20:55 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string		_name;
	public:
						DiamondTrap(void);
						DiamondTrap(std::string name);
						DiamondTrap(const DiamondTrap& diamondTrap);
		DiamondTrap&	operator=(const DiamondTrap& diamondTrap);
						~DiamondTrap(void);

		void			whoAmI(void);
		void			attack(const std::string& target);
		void			printStatus(void);
};

#endif