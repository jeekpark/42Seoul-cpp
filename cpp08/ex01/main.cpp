/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:17:06 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/10 02:10:42 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Span.hpp"
#include <climits>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

int main(void)
{
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	
	{
		Span span(3);
		span.addNumber(INT_MIN);
		span.addNumber(INT_MAX);
		span.addNumber(INT_MAX / 10);
		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;
	}
	
	{
		std::srand(static_cast<unsigned int>(time(NULL)));
		std::vector<int> v;
		for (std::size_t i = 0; i < 10000; ++i)
			v.push_back(std::rand());
		Span span(10000);
		span.addNumber(v.begin(), v.end());
		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;
	}
	return 0;
}