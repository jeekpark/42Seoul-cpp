/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 01:03:34 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/05 21:08:56 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScalarConverter.hpp"

#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>


/* public */
void	ScalarConverter::convert(const std::string& literal)
{
	mLiteral = literal;
}

void	ScalarConverter::printChar(void)
{
	std::cout << "char: ";
	if (isChar())
	{
		if ((0 <= static_cast<int>(mLiteral[1]))
			&& std::iscntrl(static_cast<int>(mLiteral[1])) == false)
		{
			std::cout << '\'' << mLiteral[1] << '\'' << std::endl;
		}
		else
		{
			std::cout << "impossible" << std::endl;
		}
	}
	else if (isInt())
	{
		long longValue = std::strtol(mLiteral.c_str(), NULL, 10);
		int intValue = static_cast<int>(longValue);
		if (static_cast<int>(std::numeric_limits<char>::min()) <= intValue
			&& intValue <= static_cast<int>(std::numeric_limits<char>::max()))
		{
			if (iscntrl(intValue) == false
				&& (0 <= intValue && intValue < 128))
			{
				std::cout << '\'' << static_cast<char>(intValue) << '\'' << std::endl;
			}
			else 
			{
				std::cout << "Non displayable" << std::endl;
			}
		}
		else
		{
			std::cout << "impossible" << std::endl;
		}
	}
	else if (isFloat())
	{
		double doubleValue = std::strtod(mLiteral.c_str(), NULL);
		float floatValue = static_cast<float>(doubleValue);
		if (static_cast<float>(std::numeric_limits<char>::min()) <= floatValue
			&& floatValue <= static_cast<float>(std::numeric_limits<char>::max()))
		{
			if ((0.0f <= floatValue && floatValue < 128.0f)
				&& iscntrl(static_cast<int>(floatValue)) == false)
			{
				std::cout << '\'' << static_cast<char>(floatValue) << '\'' << std::endl;
			}
			else
			{
				std::cout << "Non displayable" << std::endl;
			}
		}
		else
		{
			std::cout << "impossible" << std::endl;
		}
	}
	else if (isDouble())
	{
		double doubleValue = std::strtod(mLiteral.c_str(), NULL);;
		if (static_cast<double>(std::numeric_limits<char>::min()) <= doubleValue
			&& doubleValue <= static_cast<double>(std::numeric_limits<char>::max()))
		{
			if (0.0 <= doubleValue && doubleValue < 128.0
				&& iscntrl(static_cast<int>(doubleValue)) == false)
			{
				std::cout << '\'' << static_cast<char>(doubleValue) << '\'' << std::endl;
			}
			else
			{
				std::cout << "Non displayable" << std::endl;
			}
		}
		else
		{
			std::cout << "impossible" << std::endl;
		}
	}
	else
	{
		std::cout << "impossible" << std::endl;
	}
}

void	ScalarConverter::printInt(void)
{
	std::cout << "int: ";
	if (isChar())
	{
		std::cout << static_cast<int>(mLiteral[1]) << std::endl;
	}
	else if (isInt())
	{
		std::cout << static_cast<int>(std::strtol(mLiteral.c_str(), NULL, 10)) << std::endl;
	}
	else if (isFloat())
	{
		float floatValue = static_cast<float>(std::strtod(mLiteral.c_str(), NULL));
		if (static_cast<float>(std::numeric_limits<int>::min()) <= floatValue
			&& floatValue <= static_cast<float>(std::numeric_limits<int>::max()))
		{
			std::cout << static_cast<int>(floatValue) << std::endl;
		}
		else
		{
			std::cout << "impossible" << std::endl;
		}
	}
	else if (isDouble())
	{
		double doubleValue = std::strtod(mLiteral.c_str(), NULL);
		if (static_cast<double>(std::numeric_limits<int>::min()) <= doubleValue
			&& doubleValue <= static_cast<double>(std::numeric_limits<int>::max()))
		{
			std::cout << static_cast<int>(doubleValue) << std::endl;
		}
		else
		{
			std::cout << "impossible" << std::endl;
		}
	}
	else
	{
		std::cout << "impossible" << std::endl;
	}
}


void	ScalarConverter::printFloat(void)
{
	std::cout << "float: ";
	if (isChar())
	{
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(mLiteral[1]) << "f" << std::endl;
	}
	else if (isInt())
	{
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(std::strtol(mLiteral.c_str(), NULL, 10)) << "f" << std::endl;
	}
	else if (isFloat())
	{
		std::cout << std::fixed << std::setprecision(std::numeric_limits<float>::digits10) << static_cast<float>(std::strtod(mLiteral.c_str(), NULL)) << "f" << std::endl;
	}
	else if (isDouble())
	{
		double doubleValue = std::strtod(mLiteral.c_str(), NULL);
		if (-static_cast<double>(std::numeric_limits<float>::max()) <= doubleValue
			&& doubleValue <= static_cast<double>(std::numeric_limits<float>::max()))
		{
			std::cout << std::fixed << std::setprecision(std::numeric_limits<float>::digits10) << static_cast<float>(doubleValue) << "f" << std::endl;
		}
		else if (mLiteral == std::string("nan") || mLiteral == std::string("+inf") || mLiteral == std::string("-inf"))
		{
			std::cout << mLiteral << "f" << std::endl;
		}
		else
		{
			std::cout << "impossible" << std::endl;
		}
	}
	else
	{
		std::cout << "impossible" << std::endl;
	}
}

void	ScalarConverter::printDouble(void)
{
	std::cout << "double: ";
	if (isChar())
	{
		std::cout << std::fixed << std::setprecision(1) << static_cast<double>(mLiteral[1]) << std::endl;
	}
	else if (isInt())
	{
		std::cout << std::fixed << std::setprecision(1) << static_cast<double>(std::strtol(mLiteral.c_str(), NULL, 10)) << std::endl;
	}
	else if (isFloat())
	{
		std::cout << std::fixed << std::setprecision(std::numeric_limits<double>::digits10) << static_cast<double>(std::strtod(mLiteral.c_str(), NULL)) << std::endl;
	}
	else if (isDouble())
	{
		std::cout << std::fixed << std::setprecision(std::numeric_limits<double>::digits10) << static_cast<double>(std::strtod(mLiteral.c_str(), NULL)) << std::endl;
	}
	else
	{
		std::cout << "impossible" << std::endl;
	}
}



/* private */
std::string ScalarConverter::mLiteral;

bool 	ScalarConverter::isChar(void)
{
	if (mLiteral.length() == 3
		&& mLiteral[0] == '\''
		&& mLiteral[2] == '\'')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool	ScalarConverter::isInt(void)
{
	char* endPtr = NULL;
	const char* cStr = mLiteral.c_str();
	long longValue = std::strtol(cStr, &endPtr, 10);
	if (mLiteral.length() != 0
		&& *endPtr == '\0'
		&& (static_cast<long>(std::numeric_limits<int>::min()) <= longValue 
			&& longValue <= static_cast<long>(std::numeric_limits<int>::max())))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool	ScalarConverter::isFloat(void)
{
	if (mLiteral == std::string("nanf")
		|| mLiteral == std::string("+inff")
		|| mLiteral == std::string("-inff"))
	{
		return true;
	}
	char* endPtr = NULL;
	const char* cStr = mLiteral.c_str();
	double doubleValue = std::strtod(cStr, &endPtr);
	size_t dotCount = 0;
	for (size_t i = 0; cStr[i]; ++i)
	{
		if (cStr[i] == '.')
		{
			++dotCount;
		}
	}
	if (dotCount != 1)
	{
		return false;
	}
	if (mLiteral.length() >= 3
		&& endPtr != NULL
		&& endPtr[0] == 'f'
		&& endPtr[1] == '\0'
		&& (-static_cast<double>(std::numeric_limits<float>::max()) <= doubleValue
			&& doubleValue <= static_cast<double>(std::numeric_limits<float>::max())))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool	ScalarConverter::isDouble(void)
{
	if (mLiteral == std::string("nan")
		|| mLiteral == std::string("+inf")
		|| mLiteral == std::string("-inf"))
	{
		return true;
	}
	char* endPtr = NULL;
	const char* cStr = mLiteral.c_str();
	double doubleValue = std::strtod(cStr, &endPtr);
	if (mLiteral.length() >= 2
		&& endPtr != NULL
		&& *endPtr == '\0'
		&& (-std::numeric_limits<double>::max() <= doubleValue
			&& doubleValue <= std::numeric_limits<double>::max()))
	{
		return true;
	}
	else
	{
		return false;
	}
}