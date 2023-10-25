/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 22:11:49 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/25 12:00:34 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


int main()
{
	Bureaucrat a("jeekpark", 3);
	a.increaseGrade();
	a.increaseGrade();
	try
	{
		a.increaseGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	//a.increaseGrade();
	std::cout << (int)a.getGrade() << std::endl;
}