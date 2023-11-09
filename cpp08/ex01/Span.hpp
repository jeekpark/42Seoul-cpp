/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 21:52:08 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/10 02:10:53 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span
{
public:
									Span(unsigned int capacity);
									Span(const Span& copy);
	Span&							operator=(const Span& copy);
									~Span(void);

	void							addNumber(int number);
	template<typename Iter> void	addNumber(Iter begin, Iter end)
									{
										while (begin != end) addNumber(*begin++);
									}
	unsigned int					shortestSpan(void) const;
	unsigned int					longestSpan(void) const;

private:
	unsigned int					mCapacity;
	std::vector<int>				mNumbers;
};

#endif