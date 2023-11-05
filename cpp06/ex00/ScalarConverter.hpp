/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 00:58:54 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/05 20:59:04 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
public:
	static void			convert(const std::string& literal);
	static void			printChar(void);
	static void			printInt(void);
	static void			printFloat(void);
	static void			printDouble(void);
private:
	static std::string	mLiteral;
	static bool			isChar(void);
	static bool			isInt(void);
	static bool			isFloat(void);
	static bool			isDouble(void);
};

#endif