/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:56:40 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/27 20:13:16 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
							RobotomyRequestForm(std::string target);
							RobotomyRequestForm(const RobotomyRequestForm& copy);
	virtual					~RobotomyRequestForm(void);
	RobotomyRequestForm&	operator=(const RobotomyRequestForm& copy);
	virtual void			execute(const Bureaucrat& executor) const;
private:
	std::string				mTarget;

	const std::string&		getTarget(void) const;
	void					setTarget(std::string target);
};

#endif