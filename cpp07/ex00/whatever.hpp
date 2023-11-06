/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:09:13 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/06 16:56:54 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WHATEVER_H
#define WHATEVER_H

template<typename T> void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T> T& min(T& a, T& b)
{
	if (a < b)
		return a;
	else
	 	return b;
}

template<typename T> T& max(T& a, T& b)
{
	if (a > b)
		return a;
	else
		return b;
}


#endif