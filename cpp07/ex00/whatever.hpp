/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:09:13 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/07 15:38:14 by jeekpark         ###   ########.fr       */
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

template<typename T> T& min(T& a, T& b) { return a < b ? a : b; }
template<typename T> T& max(T& a, T& b) { return a > b ? a : b; }
template<typename T> const T& min(const T& a, const T& b) { return a < b ? a : b; }
template<typename T> const T& max(const T& a, const T& b) { return a > b ? a : b; }


#endif