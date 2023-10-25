/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:56:46 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/25 21:33:13 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"


int main()
{

	/**
	 * @brief test for usage
	 * 
	 */
	{
		Bureaucrat	staff("Polar", 7);
		Form		paper("TIG apology", 10, 10);

		staff.signForm(paper);
		std::cout << paper << std::endl;

		std::cout << std::endl;
	}


	/**
	 * @brief test for Form::DoubleSignException
	 * 
	 */
	{
		Bureaucrat	staff("Polar", 7);
		Form		paper("TIG apology", 10, 10);
		
		staff.signForm(paper);
		staff.signForm(paper);
		std::cout << std::endl;
	}
	


	/**
	 * @brief test for Form::GradeTooLowException
	 * 
	 */
	{
		Bureaucrat	staff("Polar", 7);
		Form		paper("TIG apology", 1, 1);
		
		staff.signForm(paper);
		std::cout << std::endl;
	}
	return 0;
}