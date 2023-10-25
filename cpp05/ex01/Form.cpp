/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:42:32 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/25 18:06:21 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* public */
Form::Form
(
	std::string	name,
	grade_t		gradeRequiredToSign,
	grade_t		gradeRequiredToExecute
)
: mName(name)
, mGradeRequiredToSign(gradeRequiredToSign)
, mGradeRequiredToExecute(gradeRequiredToExecute)
{
	
	Form::validGrade(mGradeRequiredToSign);
	Form::validGrade(mGradeRequiredToExecute);
	setIsSigned(false);
}

Form::Form(const Form& copy)
: mName(copy.getName())
, mIsSigned(copy.getIsSigned())
, mGradeRequiredToSign(copy.getGradeRequiredToSign())
, mGradeRequiredToExecute(copy.getGradeRequiredToExecute())
{
	// Empty function body
}

Form::~Form(void)
{
	// Empty function body
}

Form&	Form::operator=(const Form& copy)
{
	(void)copy;
	throw Form::InvalidOperatorException();
}

const std::string&	Form::getName(void) const
{
	return mName;
}

bool	Form::getIsSigned(void) const
{
	return mIsSigned;
}

grade_t	Form::getGradeRequiredToSign(void) const
{
	return mGradeRequiredToSign;
}

grade_t Form::getGradeRequiredToExecute(void) const
{
	return mGradeRequiredToExecute;
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (mIsSigned)
		throw Form::DoubleSignException();
	if (bureaucrat.getGrade() > mGradeRequiredToSign)
		throw Form::GradeTooLowException();
	setIsSigned(true);
}

/* private */
void	Form::setIsSigned(bool b)
{
	mIsSigned = b;
}

void	Form::validGrade(grade_t grade)
{
	if (grade < 1)
		throw Form::GradeTooHighException();
	if (150 < grade)
		throw Form::GradeTooLowException();
}