/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:56:46 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/27 23:09:08 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{

	/**
	 * @brief test for Intern
	 * 
	 */
	{
		Intern	stuff;
		AForm*	paper;
		try
		{
			paper = stuff.makeForm("presidential pardon", "you");
		}
		catch(const std::exception& e)
		{
			std::cout << "Something wrong." << std::endl;
		}
		std::cout << *paper << std::endl << std::endl;

		Bureaucrat man("Polar", 3);
		man.signForm(*paper);
		man.exectueForm(*paper);

		std::cout << std::endl << *paper << std::endl << std::endl;
		
		delete paper;
	}



	return 0;
}