/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:36:19 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/25 18:06:28 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <string>
#include <iostream>

#include "Bureaucrat.hpp"

class Form
{
public:
	class GradeTooHighException			: public std::exception {};
	class GradeTooLowException			: public std::exception {};
	class InvalidOperatorException		: public std::exception {};
	class DoubleSignException			: public std::exception {};

						Form
						(
							std::string	name,
							grade_t		gradeRequiredToSign,
							grade_t		gradeRequiredToExecute
						);
						Form(const Form& copy);
						~Form(void);
	Form&				operator=(const Form& copy);
	
	const std::string&	getName(void) const;
	bool				getIsSigned(void) const;
	grade_t				getGradeRequiredToSign(void) const;
	grade_t				getGradeRequiredToExecute(void) const;

	void				beSigned(const Bureaucrat& bureaucrat);

private:
	const std::string	mName;
	bool				mIsSigned;
	const grade_t		mGradeRequiredToSign;
	const grade_t		mGradeRequiredToExecute;

	void				setIsSigned(bool b);

	static void			validGrade(grade_t grade);
};

#endif