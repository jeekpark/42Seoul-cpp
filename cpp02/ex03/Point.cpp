/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:38:15 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/04 23:50:55 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : _x( 0 ), _y( 0 )
{}

Point::Point( const float x, const float y ) : _x( x ), _y( y )
{}

Point::Point( const Point& point ) : _x( point.getX() ), _y( point.getY() )
{}

Point&	Point::operator=( const Point& point )
{
	if (this != &point)
	{
		const_cast<Fixed&>(_x) = point.getX();
		const_cast<Fixed&>(_y) = point.getY();
	}
	return *this;
}

Point::~Point( void )
{}

Fixed	Point::getX( void ) const
{
	return _x;
}

Fixed	Point::getY( void ) const
{
	return _y;
}

