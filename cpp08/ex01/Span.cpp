/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 22:31:52 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/10 02:19:32 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Span.hpp"
#include <algorithm>
#include <exception>
#include <limits>
#include <vector>

/* public */
Span::Span(unsigned int capacity)
: mCapacity(capacity)
, mNumbers(std::vector<int>())
{}

Span::Span(const Span& copy)
: mCapacity(copy.mCapacity)
, mNumbers(copy.mNumbers)
{}

Span& Span::operator=(const Span& copy)
{
	if (this != &copy)
	{
		mCapacity = copy.mCapacity;
		mNumbers = copy.mNumbers;
	}
	return *this;
}

Span::~Span(void)
{}

void Span::addNumber(int number)
{
	if (mNumbers.size() == mCapacity)
		throw std::exception();
	mNumbers.push_back(number);
}

unsigned int Span::shortestSpan(void) const
{
	if (mNumbers.size() <= 1)
		throw std::exception();
	std::vector<int> copy(mNumbers);
	std::sort(copy.begin(), copy.end());
	unsigned int res = std::numeric_limits<unsigned int>::max();
	for (std::vector<int>::iterator it = copy.begin(); it + 1 != copy.end(); ++it)
	{
		res = std::min(res, static_cast<unsigned int>(*(it + 1) - *it));
		if (res == 0)
			return res;
	}
	return res;
}

unsigned int Span::longestSpan(void) const
{
	if (mNumbers.size() <= 1)
		throw std::exception();
	int min = std::numeric_limits<int>::max();
	int max = std::numeric_limits<int>::min();
	for (std::vector<int>::const_iterator it = mNumbers.begin(); it != mNumbers.end(); ++it)
	{
		if (min > *it)
			min = *it;
		if (max < *it)
			max = *it;
	}
	return static_cast<unsigned int>(max - min);
}
