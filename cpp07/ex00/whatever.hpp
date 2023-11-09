/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:09:13 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/09 19:35:36 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

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
template<typename T> volatile T& min(volatile T& a, volatile T& b) { return a < b ? a : b; }
template<typename T> volatile T& max(volatile T& a, volatile T& b) { return a > b ? a : b; }
template<typename T> volatile const T& min(volatile const T& a, volatile const T& b) { return a < b ? a : b; }
template<typename T> volatile const T& max(volatile const T& a, volatile const T& b) { return a > b ? a : b; }


#endif