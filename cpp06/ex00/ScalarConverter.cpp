/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:50:02 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/03 23:51:53 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <limits>


/* public */
void	ScalarConverter::convert(const std::string& literal)
{
	mLiteral = literal;
	setActualType();
	setOthersType();
}


void	ScalarConverter::printCharType(void)
{
	std::cout << "char: ";
	if (mActualType == NONE
		|| mFloatNotANumber == true
		|| mDoubleNotANumber == true)
	{
		std::cout << "impossible" <<  std::endl;
	}
	else if (iscntrl(mChar) == true)
	{
		std::cout << "Non displayable" << std::endl;
	}
	else
	{
		std::cout << '\'' << mChar << '\'' << std::endl;
	}
}

void	ScalarConverter::printIntType(void)
{
	std::cout << "int: ";
	if (mActualType == NONE
		|| mFloatNotANumber == true
		|| mDoubleNotANumber == true
		|| mIntOverflow == true)
	{
		std::cout << "impossible" << std::endl;
	}
	else
	{
		std::cout << mInt << std::endl;
	}
}


/* private */
std::string		ScalarConverter::mLiteral;
int				ScalarConverter::mActualType;

char			ScalarConverter::mChar;
int				ScalarConverter::mInt;
float			ScalarConverter::mFloat;
double			ScalarConverter::mDouble;

bool			ScalarConverter::mCharNotAscii;
bool			ScalarConverter::mIntOverflow;
bool			ScalarConverter::mFloatNotANumber;
bool			ScalarConverter::mDoubleNotANumber;

const std::string& ScalarConverter::getLiteral(void)
{
	return ScalarConverter::mLiteral;
}



static bool	isCharType(const std::string& literal)
{
	if
	(
		literal.length() == 3
		&& literal[0] == '\''
		&& literal[2] == '\''
	)
	{
		return true;
	}
	else
	{
		return false;
	}
}

static bool isIntType(const std::string& literal)
{
	char* endPtr = NULL;
	std::strtol(literal.c_str(), &endPtr, 10);
	if (endPtr == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

static bool	isFloatType(const std::string& literal)
{
	char* endPtr = NULL;
	std::strtod(literal.c_str(), &endPtr);
	if (endPtr[0] == 'f' && endPtr[1] == '\0')
	{
		return true;
	}
	else
	{
		return false;
	}
}

static bool	isDoubleType(const std::string& literal)
{
	char* endPtr = NULL;
	std::strtod(literal.c_str(), &endPtr);
	if (endPtr[0] == '\0')
	{
		return true;
	}
	else
	{
		return false;
	}
}


void	ScalarConverter::setActualType(void)
{
	if (isCharType(getLiteral()))
	{
		mActualType = CHAR;
	}
	else if (isIntType(getLiteral()))
	{
		mActualType = INT;
	}
	else if (isFloatType(getLiteral()))
	{
		mActualType = FLOAT;
	}
	else if (isDoubleType(getLiteral()))
	{
		mActualType = DOUBLE;
	}
	else
	{
		mActualType = NONE;
	}

	switch (mActualType)
	{
		long longValue;
		case CHAR:
			if (iscntrl(mLiteral[1]) == false)
			{
				mChar = mLiteral[1];
				mCharNotAscii = false;
			}
			else
			{
				mChar = 0;
				mCharNotAscii = true;
			}
			break;
		case INT:
			longValue = strtol(mLiteral.c_str(), NULL, 10);
			if ((std::numeric_limits<int>::min() <= longValue && longValue <= std::numeric_limits<int>::max())
				== false)
			{
				mIntOverflow = true;
			}
			else
			{
				mIntOverflow = false;
			}
			mInt = static_cast<int>(longValue);
			break;
		case FLOAT:
			if (mLiteral == std::string("nan")
				|| mLiteral == std::string("+nan")
				|| mLiteral == std::string("-nan"))
			{
				mFloatNotANumber = true;
			}
			else
			{
				mFloatNotANumber = false;
			}
			mFloat = static_cast<float>(strtod(mLiteral.c_str(), NULL));
			break;
		case DOUBLE:
			if (mLiteral == std::string("nan")
				|| mLiteral == std::string("+nan")
				|| mLiteral == std::string("-nan"))
			{
				mDoubleNotANumber = true;
			}
			else
			{
				mDoubleNotANumber = false;
			}
			mDouble = strtod(mLiteral.c_str(), NULL);
			break;
		default:
			break;
	}
}




void	ScalarConverter::setOthersType(void)
{
	switch (mActualType)
	{
		long longValue;
		case CHAR:
			mInt = static_cast<int>(mChar);
			mFloat = static_cast<float>(mChar);
			mDouble = static_cast<double>(mChar);
			break;
		case INT:
			if (isascii(mInt) == true)
			{
				mChar = static_cast<char>(mInt);
				mCharNotAscii = false;
			}
			else
			{
				mChar = 0;
				mCharNotAscii = true;
			}
			mFloat = static_cast<float>(mInt);
			mDouble = static_cast<double>(mInt);
			break;
		case FLOAT:
			if (isascii(static_cast<int>(mFloat) == true))
			{
				mChar = static_cast<char>(mFloat);
				mCharNotAscii = false;
			}
			else
			{
				mChar = 0;
				mCharNotAscii = true;
			}
			longValue = static_cast<long>(mFloat);
			if ((std::numeric_limits<int>::min() <= longValue && longValue <= std::numeric_limits<int>::max())
				== false)
			{
				mIntOverflow = true;
			}
			else
			{
				mIntOverflow = false;
			}
			mInt = static_cast<int>(mFloat);
			mDouble = static_cast<double>(mFloat);
			break;
		case DOUBLE:
			if (isascii(static_cast<int>(mDouble) == true))
			{
				mChar = static_cast<char>(mDouble);
				mCharNotAscii = false;
			}
			else
			{
				mChar = 0;
				mCharNotAscii = true;
			}
			longValue = static_cast<long>(mDouble);
			if ((std::numeric_limits<int>::min() <= longValue && longValue <= std::numeric_limits<int>::max())
				== false)
			{
				mIntOverflow = true;
			}
			else
			{
				mIntOverflow = false;
			}
			mInt = static_cast<int>(mDouble);
			mFloat = static_cast<float>(mDouble);
			break;
		default:
			break;
	}
}