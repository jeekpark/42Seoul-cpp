/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:19:26 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/06 14:14:20 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Serializer.hpp"
#include <atomic>
#include <cstdint>

/* public */
std::uintptr_t	Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	Serializer::deserialize(std::uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

/* private */
Serializer::Serializer(void)
{
	// Empty body function
}

Serializer::~Serializer(void)
{
	// Empty body function
}

Serializer::Serializer(const Serializer& copy)
{
	(void)copy;
}

Serializer&	Serializer::operator=(const Serializer& copy)
{
	(void)copy;
	return *this;
}