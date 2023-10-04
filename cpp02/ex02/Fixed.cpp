/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 21:05:32 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/04 21:12:41 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <math.h>

Fixed::Fixed() : _value( 0 )
{}

Fixed::~Fixed( void )
{}

Fixed::Fixed( const Fixed& fixed )
{
	*this = fixed;
}

Fixed::Fixed( const int num ) : _value( num << this->_bits )
{}

Fixed::Fixed( const float num ) : _value( roundf(num * pow( 2, this->_bits )) )
{}


Fixed& Fixed::operator=( const Fixed& fixed )
{
	if ( this != &fixed )
		this->_value = fixed.getRawBits();
	return *this;
}

bool	Fixed::operator>( const Fixed& fixed ) const
{
	return this->getRawBits() > fixed.getRawBits();
}

bool	Fixed::operator<( const Fixed& fixed ) const
{
	return this->getRawBits() < fixed.getRawBits();
}

bool	Fixed::operator>=( const Fixed& fixed ) const
{
	return this->getRawBits() >= fixed.getRawBits();
}

bool	Fixed::operator<=( const Fixed& fixed ) const
{
	return this->getRawBits() <= fixed.getRawBits();
}

bool	Fixed::operator==( const Fixed& fixed ) const
{
	return this->getRawBits() == fixed.getRawBits();
}

bool	Fixed::operator!=( const Fixed& fixed ) const
{
	return this->getRawBits() != fixed.getRawBits();
}

Fixed	Fixed::operator+( const Fixed& fixed ) const
{
	return this->toFloat() + fixed.toFloat();
}

Fixed	Fixed::operator-( const Fixed& fixed ) const
{
	return this->toFloat() - fixed.toFloat();
}

Fixed	Fixed::operator*( const Fixed& fixed ) const
{
	return this->toFloat() * fixed.toFloat();
}

Fixed	Fixed::operator/( const Fixed& fixed ) const
{
	return this->toFloat() / fixed.toFloat();
}

Fixed&	Fixed::operator++( void )
{
	this->_value++;
	return *this;
}

Fixed&	Fixed::operator--( void )
{
	this->_value--;
	return *this;
}

const Fixed	Fixed::operator++( int )
{
	const Fixed	temp = *this;
	this->_value++;
	return temp;
}

const Fixed	Fixed::operator--( int )
{
	const Fixed	temp = *this;
	this->_value--;
	return temp;
}

Fixed&	Fixed::min( Fixed& a, Fixed& b )
{
	if ( a < b )
		return a;
	else
		return b;
}

Fixed&	Fixed::max( Fixed& a, Fixed& b )
{
	if ( a > b )
		return a;
	else
		return b;
}

const Fixed&	Fixed::min( const Fixed& a, const Fixed& b )
{
	if ( a < b )
		return a;
	else
		return b;
}

const Fixed&	Fixed::max( const Fixed& a, const Fixed& b )
{
	if ( a > b )
		return a;
	else
		return b;
}

int	Fixed::getRawBits( void ) const
{
	return this->_value;
}

void	Fixed::setRawBits( const int raw )
{
	this->_value = raw;
}

float	Fixed::toFloat( void ) const
{
	return this->_value / pow( 2, this->_bits );
}

int		Fixed::toInt( void ) const
{
	return this->_value >> this->_bits;
}

std::ostream&	operator<<( std::ostream& str, const Fixed& fixed )
{
	return str << fixed.toFloat();
}