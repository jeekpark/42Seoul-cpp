/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:46:31 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/27 20:53:41 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"


/* public */
PresidentialPardonForm::PresidentialPardonForm(std::string target)
: AForm("PresidentialPardonForm", 25, 5)
, mTarget(target)
{
	// Empty function body
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy)
: AForm(copy)
, mTarget(copy.getTarget())
{
	// Empty function body
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	// Empty function body
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
	(void)copy;
	throw AForm::InvalidOperatorException();
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() > getGradeRequiredToExecute())
		throw AForm::GradeTooLowException();
	if (getIsSigned() == false)
		throw AForm::NotSignedException();
	
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

/* private */
const std::string&	PresidentialPardonForm::getTarget(void) const
{
	return mTarget;
}

void	PresidentialPardonForm::setTarget(std::string target)
{
	mTarget = target;
}