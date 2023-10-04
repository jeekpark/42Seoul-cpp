/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:25:23 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/04 21:06:17 by jeekpark         ###   ########.fr       */
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
		Fixed( const int num );
		Fixed( const float num );
		~Fixed( void );

		Fixed&	operator=( const Fixed& fixed );
		
		bool	operator>( const Fixed& fixed ) const;
		bool	operator<( const Fixed& fixed ) const;
		bool	operator>=( const Fixed& fixed ) const;
		bool	operator<=( const Fixed& fixed ) const;
		bool	operator==( const Fixed& fixed ) const;
		bool	operator!=( const Fixed& fixed ) const;

		Fixed	operator+( const Fixed& fixed ) const;
		Fixed	operator-( const Fixed& fixed ) const;
		Fixed	operator*( const Fixed& fixed ) const;
		Fixed	operator/( const Fixed& fixed ) const;

		Fixed&	operator++( void );
		Fixed&	operator--( void );
		const Fixed	operator++( int );
		const Fixed	operator--( int );

		static Fixed&	min( Fixed& a, Fixed& b );
		static Fixed&	max( Fixed& a, Fixed& b );
		static const Fixed&	min( const Fixed& a, const Fixed& b );
		static const Fixed&	max( const Fixed& a, const Fixed& b );

		int		getRawBits( void ) const;
		void	setRawBits( const int raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream&	operator<<( std::ostream &str, const Fixed& fixed );

#endif