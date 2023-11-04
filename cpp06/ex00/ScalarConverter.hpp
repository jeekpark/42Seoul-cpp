/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:05:03 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/04 17:11:07 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>


class ScalarConverter
{
public:
	static void					convert(const std::string& literal);
	static void					printCharType(void);
	static void					printIntType(void);

private:
	enum eActualType
	{
		CHAR,
		INT,
		FLOAT,
		DOUBLE,
		NONE
	};
	
	static std::string			mLiteral;
	
	static int					mActualType; 
	static char					mChar;
	static int					mInt;
	static float				mFloat;
	static double				mDouble;
	
	static bool					mCharNotAscii;
	static bool					mIntOverflow;
	static bool					mFloatError;
	static bool					mDoubleError;
	static const std::string&	getLiteral(void);
	static void					setActualType(void);
	static void					setOthersType(void);
};

#endif