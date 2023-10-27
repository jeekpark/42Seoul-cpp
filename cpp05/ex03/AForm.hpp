/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:36:19 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/27 19:53:14 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <string>
#include <iostream>

#include "Bureaucrat.hpp"

class AForm
{
public:
	class GradeTooHighException			: public std::exception {};
	class GradeTooLowException			: public std::exception {};
	class InvalidOperatorException		: public std::exception {};
	class DoubleSignException			: public std::exception {};
	class NotSignedException			: public std::exception {};

						AForm
						(
							std::string	name,
							grade_t		gradeRequiredToSign,
							grade_t		gradeRequiredToExecute
						);
						AForm(const AForm& copy);
	virtual				~AForm(void);
	AForm&				operator=(const AForm& copy);
	
	const std::string&	getName(void) const;
	bool				getIsSigned(void) const;
	grade_t				getGradeRequiredToSign(void) const;
	grade_t				getGradeRequiredToExecute(void) const;

	void				beSigned(const Bureaucrat& bureaucrat);
	virtual void		execute(const Bureaucrat& executor) const = 0;

private:
	const std::string	mName;
	bool				mIsSigned;
	const grade_t		mGradeRequiredToSign;
	const grade_t		mGradeRequiredToExecute;

	void				setIsSigned(bool b);

	static void			validGrade(grade_t grade);
};

std::ostream&	operator<<(std::ostream& outStream, const AForm& form);

#endif