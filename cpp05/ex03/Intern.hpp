/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 21:08:35 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/27 23:02:55 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef INTERN_HPP
#define INTERN_HPP

#include <exception>

#include "AForm.hpp"

class Intern
{
public:
	class TypeNotFound : public std::exception {};
			Intern(void);
			Intern(const Intern& copy);
			~Intern(void);
	Intern&	operator=(const Intern& copy);
	
	AForm*	makeForm(std::string type, std::string target);
};

#endif