/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:56:26 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/25 21:32:04 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
/* public */

Bureaucrat::Bureaucrat(std::string name, grade_t grade)
: mName(name)
{
	setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
: mName(copy.getName())
, mGrade(copy.getGrade())
{
	// Empty function body
}

Bureaucrat::~Bureaucrat(void)
{
	// Empty function body
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& copy)
{
	(void)copy;
	throw Bureaucrat::InvalidOperatorException();
}

const std::string&	Bureaucrat::getName(void) const
{
	return mName;
}

grade_t	Bureaucrat::getGrade(void) const
{
	return mGrade;
}

void	Bureaucrat::increaseGrade(void)
{
	setGrade(getGrade() - 1);
}

void	Bureaucrat::decreaseGrade(void)
{
	setGrade(getGrade() + 1);
}


void	Bureaucrat::signForm(Form& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << "." << std::endl;
	}
	catch(const Form::DoubleSignException& e)
	{
		std::cout << getName() << " couldn't sign " << form.getName()
			<< " because this form is already signed." << std::endl;
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cout << getName() << " couldn't sign " << form.getName()
			<< " because " << getName() << "(grade: " << (int)getGrade() << ")"
			<< " is below the required grade("
			<< (int)form.getGradeRequiredToSign() << ") to sign." << std::endl;
	}
}



/* private */



void	Bureaucrat::setGrade(grade_t grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	mGrade = grade;
}

/* etc */

std::ostream&	operator<<(std::ostream& outStream, const Bureaucrat& bureaucrat)
{
	outStream << bureaucrat.getName() << ", bureaucrat grade " << (int)bureaucrat.getGrade() << ".";
	return outStream;
}