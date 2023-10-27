/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:56:46 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/27 20:40:12 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"


int main()
{

	/**
	 * @brief test for ShrubberyCreationForm
	 * 
	 */
	{
		Bureaucrat	staff("Polar", 7);
		AForm*		paper = new ShrubberyCreationForm("home");

		staff.signForm(*paper);
		staff.exectueForm(*paper);
		std::cout << *paper << std::endl;

		std::cout << std::endl;
	}

	/**
	 * @brief test for RobotomyRequestForm
	 * 
	 */
	{
		Bureaucrat	staff("Polar", 7);
		AForm*		paper = new RobotomyRequestForm("jeekpark");

		staff.signForm(*paper);
		staff.exectueForm(*paper);
		std::cout << *paper << std::endl;

		std::cout << std::endl;
	}

	return 0;
}