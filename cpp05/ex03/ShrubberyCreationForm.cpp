/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:19:53 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/04 12:42:06 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include <fstream>


/* public */
ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm("ShrubberyCreationForm", 145, 137)
, mTarget(target)
{
	// Empty function body
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
: AForm(copy)
, mTarget(copy.getTarget())
{
	//Empty function body
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	//Empty function body
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	(void)copy;
	throw AForm::InvalidOperatorException();
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() > getGradeRequiredToExecute())
		throw AForm::GradeTooLowException();
	if (getIsSigned() == false)
		throw AForm::NotSignedException();

	std::ofstream file((getTarget() + std::string("_shrubbery")).c_str());
	if (file.fail())
		throw ShrubberyCreationForm::FailedToOpenFile();
	file << "  \\/\n__|___\n";
	if (file.fail())
		throw ShrubberyCreationForm::FailedToWriteToFile();
	file.close();
}


/* private */
const std::string&	ShrubberyCreationForm::getTarget(void) const
{
	return mTarget;
}

void	ShrubberyCreationForm::setTarget(std::string target)
{
	mTarget = target;
}