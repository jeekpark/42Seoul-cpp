/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 21:05:32 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/05 16:16:30 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <math.h>



Fixed::Fixed() : _value( 0 )
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const Fixed& fixed )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed( const int num ) : _value( num << this->_bits )
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float num ) : _value( roundf(num * this->_pow_int( 2, this->_bits )) )
{
	std::cout << "Float constructor called" << std::endl;
}


Fixed& Fixed::operator=( const Fixed& fixed )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &fixed )
		this->_value = fixed.getRawBits();
	return *this;
}


int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void	Fixed::setRawBits( const int raw )
{
	this->_value = raw;
}


float	Fixed::toFloat( void ) const
{
	return (float)this->_value / (float)this->_pow_int( 2, this->_bits );
}

int		Fixed::toInt( void ) const
{
	return this->_value >> this->_bits;
}

std::ostream&	operator<<( std::ostream& str, const Fixed& fixed )
{
	return str << fixed.toFloat();
}


int	Fixed::_pow_int( int base, int exponent ) const
{
	int	res = 1;
	if ( exponent == 0 ) return 1;
	else if ( exponent < 0 ) return 0;
	for ( int i = 0; i < exponent; i++ )
		res *= base;
	return res;
}