/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 23:51:11 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/05 00:40:31 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	_pow( Fixed n, unsigned int pow )
{
	Fixed	res( 1.0f );
	for ( unsigned int i = 0; i < pow; i++ )
		res = res + n;
	return res;
}

static Fixed	_fabs( Fixed n )
{
	if ( n < 0 ) return n * -1;
	return n;
}

static Fixed	_sqrt( Fixed sq )
{
	if ( sq < 0 ) return -1;
	if ( sq == 0 || sq == 1 ) return sq;

	Fixed	tolerance( 0.000001f );
	Fixed	x = sq;
	Fixed	prevX( 0 );

	while ( _fabs( x - prevX ) > tolerance )
	{
		prevX = x;
		x = Fixed( 0.5f ) * ( x + sq / x );
	}
	return x;
}
static Fixed	_euclideanDistance( const Point a, const Point b )
{
	return _sqrt( _pow( ( a.getX() - b.getX() ), 2 ) + _pow( ( a.getY() - b.getY() ), 2 ) );
}

static Fixed	_triangleArea( const Point a, const Point b, const Point c )
{
	Fixed	x( _euclideanDistance( a, b ) );
	Fixed	y( _euclideanDistance( b, c ) );
	Fixed	z( _euclideanDistance( a, c ) );
	Fixed	semiPeri( ( x + y + z ) / 2.0f );

	return _sqrt( semiPeri * ( semiPeri - x ) * ( semiPeri - y ) * (semiPeri - z ) );
}
bool	bsp( const Point a, const Point b, const Point c, const Point point)
{
	Fixed	triangleAreaX( _triangleArea( a, point , b ) );
	Fixed	triangleAreaY( _triangleArea( b, point , c ) );
	Fixed	triangleAreaZ( _triangleArea( a, point , c ) );
	Fixed	triangleAreaTotal( _triangleArea( a, b, c ) );
	if ( ( triangleAreaX + triangleAreaY + triangleAreaZ ) > triangleAreaTotal )
		return false;
	else
		return true;
}