/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:16:22 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/06 14:14:27 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>

#include "Data.h"

class Serializer
{
public:
	static std:: uintptr_t	serialize(Data* ptr);
	static Data*			deserialize(std::uintptr_t raw);
private:
							Serializer(void);
							~Serializer(void);
							Serializer(const Serializer& copy);
	Serializer&				operator=(const Serializer& copy);
};

#endif