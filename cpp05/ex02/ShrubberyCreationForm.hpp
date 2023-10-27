/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:30:41 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/27 20:05:12 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	class FailedToOpenFile		: public std::exception {};
	class FailedToWriteToFile	: public std::exception {};

							ShrubberyCreationForm(std::string target);
							ShrubberyCreationForm(const ShrubberyCreationForm& copy);
	virtual					~ShrubberyCreationForm(void);
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& copy);
	virtual void			execute(const Bureaucrat& executor) const;
private:
	std::string				mTarget;

	const std::string&		getTarget(void) const;
	void					setTarget(std::string target);
};

#endif