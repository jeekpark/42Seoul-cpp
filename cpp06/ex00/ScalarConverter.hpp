/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:05:03 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/29 17:27:42 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

enum eType
{
	Char,
	Int,
	Float,
	Double,
	None
};

class ScalarConverter
{
public:
	static void					convert(const std::string& literal);

	static const std::string&	getLiteral(void);
	static char					getChar(void);
	static int					getInt(void);
	static float				getFloat(void);
	static double				getDouble(void);

private:
	static std::string			mLiteral;
	static char					mChar;
	static int					mInt;
	static float				mFloat;
	static double				mDouble;

	static int					mActualType; 
};

#endif