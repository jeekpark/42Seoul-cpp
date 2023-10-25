/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:56:46 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/25 15:12:53 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	/**
	 * @brief test for Bureaucrat::GradeTooHighException
	 * 
	 */
	{
		Bureaucrat employee("jeekpark", 10);
		try
		{
			for (;;)
			{
				employee.increaseGrade();
				std::cout << employee << std::endl;
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	/**
	 * @brief test for Bureaucrat::GradeTooLowException
	 * 
	 */
	{
		Bureaucrat employee("jeekpark", 140);
		try
		{
			for (;;)
			{
				employee.decreaseGrade();
				std::cout << employee << std::endl;
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	return 0;
}