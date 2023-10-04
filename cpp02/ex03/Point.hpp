/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:32:51 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/05 00:40:43 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		const Fixed		_x;
		const Fixed		_y;
	public:
		Point( void );
		Point( const float x, const float y);
		Point( const Point& point );
		Point&	operator=( const Point& point );
		~Point( void );
		
		Fixed	getX( void ) const;
		Fixed	getY( void ) const;

};

bool	bsp( const Point a, const Point b, const Point c, const Point point);

#endif