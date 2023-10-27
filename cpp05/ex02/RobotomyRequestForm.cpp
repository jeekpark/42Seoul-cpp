/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:12:23 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/27 20:26:21 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: AForm("RobotomyRequestForm", 72, 45)
, mTarget(target)
{
	// Empty function body
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
: AForm(copy)
, mTarget(copy.getTarget())
{
	// Empty function body
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	// Empty function body
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
	(void)copy;
	throw AForm::InvalidOperatorException();
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() > getGradeRequiredToExecute())
		throw AForm::GradeTooLowException();
	if (getIsSigned() == false)
		throw AForm::NotSignedException();
	
	std::cout << "drill!! drill!!! drill!!!" << std::endl;
	srand(time(0));
	if  (std::rand() % 2)
		std::cout << getTarget() << " is robot now." << std::endl;
	else
		std::cout << getTarget() << " is failed to be robot." << std::endl;
}


/* private */
const std::string&	RobotomyRequestForm::getTarget(void) const
{
	return mTarget;
}

void	RobotomyRequestForm::setTarget(std::string target)
{
	mTarget = target;
}