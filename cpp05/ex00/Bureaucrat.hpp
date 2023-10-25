/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:22:23 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/25 15:14:29 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>

#define unsigned char uint8_t;

class Bureaucrat
{
public:
	class GradeTooHighException			: public std::exception {};
	class GradeTooLowException			: public std::exception {};
	class InvalidConstructorException	: public std::exception {};
	class InvalidOperatorException		: public std::exception {};
	
						Bureaucrat(std::string name, uint8_t grade);
						Bureaucrat(const Bureaucrat& copy);
						~Bureaucrat(void);

	const std::string&	getName(void) const;
	uint8_t				getGrade(void) const;

	void				increaseGrade(void);
	void				decreaseGrade(void);
private:
	const std::string	mName;
	uint8_t				mGrade;

						Bureaucrat(void);
	Bureaucrat&			operator=(const Bureaucrat& copy);
	
	void				setGrade(uint8_t grade);
};

std::ostream&	operator<<(std::ostream& outStream, const Bureaucrat& bureaucrat);

#endif