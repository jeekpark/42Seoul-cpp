/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:41:48 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/27 20:54:43 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
							PresidentialPardonForm(std::string target);
							PresidentialPardonForm(const PresidentialPardonForm& copy);
	virtual					~PresidentialPardonForm(void);
	PresidentialPardonForm&	operator=(const PresidentialPardonForm& copy);
	
	virtual void			execute(const Bureaucrat& executor) const;
private:
	std::string				mTarget;

	const std::string&		getTarget(void) const;
	void					setTarget(std::string target);
};

#endif