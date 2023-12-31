/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:25:23 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/03 12:18:40 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					_value;
		const static int	_bits = 8;

	public:
		Fixed( void );
		Fixed( const Fixed& fixed );
		Fixed& operator=( const Fixed& fixed );
		~Fixed( void );

		int		getRawBits( void ) const;
		void	setRawBits( const int raw );
};

#endif