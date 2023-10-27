/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 21:11:43 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/27 23:08:36 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void)
{
	// Empty function body
}

Intern::Intern(const Intern& copy)
{
	(void)copy;
}

Intern::~Intern(void)
{
	// Empty function body
}

Intern&	Intern::operator=(const Intern& copy)
{
	(void)copy;
	return *this;
}

static AForm*	newShrubberyCreationForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}

static AForm*	newRobotomyRequestForm(std::string target)
{
	return new RobotomyRequestForm(target);
}

static AForm*	newPresidentialPardonForm(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm*	Intern::makeForm(std::string type, std::string target)
{
	const size_t formNum = 3;
	std::string	formTypes[formNum] =
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm* (*f[formNum])(std::string) =
	{
		newShrubberyCreationForm,
		newRobotomyRequestForm,
		newPresidentialPardonForm
	};
	for (size_t i = 0; i < formNum; ++i)
	{
		if (formTypes[i] == type)
		{
			return f[i](target);
		}
	}
	throw Intern::TypeNotFound();
	return (AForm*)0;
}