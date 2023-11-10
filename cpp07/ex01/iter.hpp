/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:38:57 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/10 11:38:46 by jeekpark         ###   ########.fr       */
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