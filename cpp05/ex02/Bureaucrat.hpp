/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:22:23 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/26 16:26:54 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>

typedef unsigned char	uint8_t;
typedef uint8_t			grade_t;

class AForm;

class Bureaucrat
{
public:
	class GradeTooHighException			: public std::exception {};
	class GradeTooLowException			: public std::exception {};
	class InvalidConstructorException	: public std::exception {};
	class InvalidOperatorException		: public std::exception {};
	
						Bureaucrat(std::string name, grade_t grade);
						Bureaucrat(const Bureaucrat& copy);
						~Bureaucrat(void);
	Bureaucrat&			operator=(const Bureaucrat& copy);

	const std::string&	getName(void) const;
	grade_t				getGrade(void) const;

	void				increaseGrade(void);
	void				decreaseGrade(void);
	void				signForm(AForm& form) const;
	void				exectueForm(const AForm& form) const;
	
private:
	const std::string	mName;
	grade_t				mGrade;

	void				setGrade(grade_t grade);
};

std::ostream&	operator<<(std::ostream& outStream, const Bureaucrat& bureaucrat);

#endif