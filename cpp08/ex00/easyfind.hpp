/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:16:35 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/09 21:50:42 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

template <typename T> typename T::iterator easyfind(T& container, int i)
{
	typename T::iterator it = std::find(container.begin(), container.end(), i);
	if (it == container.end())
		throw std::exception();
	return it;
}

#endif