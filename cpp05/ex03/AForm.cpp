/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:42:32 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/25 21:45:51 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/* public */
AForm::AForm
(
	std::string	name,
	grade_t		gradeRequiredToSign,
	grade_t		gradeRequiredToExecute
)
: mName(name)
, mGradeRequiredToSign(gradeRequiredToSign)
, mGradeRequiredToExecute(gradeRequiredToExecute)
{
	
	AForm::validGrade(mGradeRequiredToSign);
	AForm::validGrade(mGradeRequiredToExecute);
	setIsSigned(false);
}

AForm::AForm(const AForm& copy)
: mName(copy.getName())
, mIsSigned(copy.getIsSigned())
, mGradeRequiredToSign(copy.getGradeRequiredToSign())
, mGradeRequiredToExecute(copy.getGradeRequiredToExecute())
{
	// Empty function body
}

AForm::~AForm(void)
{
	// Empty function body
}

AForm&	AForm::operator=(const AForm& copy)
{
	(void)copy;
	throw AForm::InvalidOperatorException();
}

const std::string&	AForm::getName(void) const
{
	return mName;
}

bool	AForm::getIsSigned(void) const
{
	return mIsSigned;
}

grade_t	AForm::getGradeRequiredToSign(void) const
{
	return mGradeRequiredToSign;
}

grade_t AForm::getGradeRequiredToExecute(void) const
{
	return mGradeRequiredToExecute;
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (mIsSigned)
		throw AForm::DoubleSignException();
	if (bureaucrat.getGrade() > mGradeRequiredToSign)
		throw AForm::GradeTooLowException();
	setIsSigned(true);
}

/* private */
void	AForm::setIsSigned(bool b)
{
	mIsSigned = b;
}

void	AForm::validGrade(grade_t grade)
{
	if (grade < 1)
		throw AForm::GradeTooHighException();
	if (150 < grade)
		throw AForm::GradeTooLowException();
}



/* etc */
std::ostream&	operator<<(std::ostream& outStream, const AForm& form)
{
	std::string	approval;
	if (form.getIsSigned())
		approval = "Signed";
	else
		approval = "Not Signed";
	outStream
		<< "Form name:\t\t\t"
		<< form.getName()
		<< "\nApproval:\t\t\t"
		<< approval
		<< "\nRequired grade to sign:\t\t"
		<< (int)form.getGradeRequiredToSign()
		<< "\nRequired grade to execute:\t"
		<< (int)form.getGradeRequiredToExecute();
	return outStream;
}