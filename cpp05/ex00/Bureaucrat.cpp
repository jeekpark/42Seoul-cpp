/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 22:01:40 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/25 11:55:54 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


/* public */

Bureaucrat::Bureaucrat(std::string name, uint8_t grade)
: mName(name)
{
	setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
: mName(copy.getName())
{
	setGrade(copy.getGrade());
}

Bureaucrat::~Bureaucrat(void)
{
	// Empty function body
}


const std::string&	Bureaucrat::getName(void) const
{
	return mName;
}

uint8_t	Bureaucrat::getGrade(void) const
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




/* private */

Bureaucrat::Bureaucrat(void)
: mName("<null>")
{
	throw Bureaucrat::InvalidConstructorException();
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& copy)
{
	throw Bureaucrat::InvalidOperatorException();
}

void	Bureaucrat::setGrade(uint8_t grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	mGrade = grade;
}


