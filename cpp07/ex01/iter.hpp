/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:38:57 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/06 16:54:28 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template<typename Tarry, typename Tfunction> void iter(Tarry arr, size_t length, Tfunction func)
{
	for (size_t i = 0; i < length; ++i)
		func(arr[i]);
}

#endif