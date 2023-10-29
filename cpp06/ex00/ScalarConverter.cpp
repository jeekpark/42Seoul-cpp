/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:50:02 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/29 17:27:40 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

std::string	ScalarConverter::mLiteral;

char		ScalarConverter::mChar;
int			ScalarConverter::mInt;
float		ScalarConverter::mFloat;
double		ScalarConverter::mDouble;

int			ScalarConverter::mActualType;

void	ScalarConverter::convert(const std::string& literal)
{
	ScalarConverter::mLiteral = literal;

	for (size_t i = 0; literal[i]; ++i)
	{
		
	}

}

const std::string& ScalarConverter::getLiteral(void)
{
	return ScalarConverter::mLiteral;
}
