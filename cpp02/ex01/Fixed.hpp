/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:25:23 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/05 16:16:34 by jeekpark         ###   ########.fr       */
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
		int					_pow_int( int base, int exponent ) const;
	public:
		Fixed( void );
		Fixed( const Fixed& fixed );
		Fixed( const int num );
		Fixed( const float num );
		Fixed& operator=( const Fixed& fixed );
		~Fixed( void );

		int		getRawBits( void ) const;
		void	setRawBits( const int raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream&	operator<<( std::ostream &str, const Fixed& fixed );

#endif