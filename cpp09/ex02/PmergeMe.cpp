/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 08:10:14 by jeekpark          #+#    #+#             */
/*   Updated: 2023/12/30 09:39:58 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib>
#include <ctime>
#include <deque>
#include <sys/_types/_time_t.h>

PmergeMe::PmergeMe(const int argc, const char** argv)
: mArgc(argc)
, mArgv(argv)
{}

PmergeMe::PmergeMe(const PmergeMe& copy)
: mArgc(copy.mArgc)
, mArgv(copy.mArgv)
, mDeque(copy.mDeque)
, mList(copy.mList)
{}

PmergeMe::~PmergeMe()
{}

PmergeMe& PmergeMe::operator=(const PmergeMe& copy)
{
	(void) copy;
	return *this;
}

bool PmergeMe::sort()
{
	if (mArgc == 1)
	{
		std::cout << "Error" << std::endl;
		return false;
	}

	for (int i = 1; i < mArgc; ++i)
	{
		int num = std::atoi(mArgv[i]);
		if (isInt(std::string(mArgv[i])) == false
				|| num < 1)
		{
			std:: cout << "Error" << std::endl;
			return false;
		}
	}

	float dequeTimeTaken = sortDeque();
	float listTimeTaken = sortList();

	std::cout << "Before:\t";
	printArgv();
	std::cout << "\nAfter:\t";
	printDeque();
	std::cout << "\nTime to process a range of "
						<< mArgc - 1
						<< " elements with std::deque : "
						<< dequeTimeTaken
						<< " us"
						<< std::endl;
	std::cout << "\nTime to process a range of "
						<< mArgc - 1
						<< " elements with std::list : "
						<< listTimeTaken
						<< " us"
						<< std::endl;
	return true;
}

time_t PmergeMe::sortDeque()
{
	clock_t start, end;
	start = clock();

	end = clock();
	return end - start;
}

time_t PmergeMe::sortList()
{
	clock_t start, end;
	start = clock();

	end = clock();
	return end - start;
}




void PmergeMe::printArgv() const
{
	for (int i = 1; i < mArgc; ++i)
	{
		std::cout << mArgv[i] << " ";
	}
}

void PmergeMe::printDeque() const
{
	for (std::deque<int>::const_iterator it = mDeque.begin();
			 it != mDeque.end(); ++it)
	{
		std::cout << *it << " ";
	}
}

bool	PmergeMe::isInt(const std::string& literal) const
{
	char* endPtr = NULL;
	const char* cStr = literal.c_str();
	long longValue = std::strtol(cStr, &endPtr, 10);
	if (literal.length() != 0
		&& *endPtr == '\0'
		&& (static_cast<long>(std::numeric_limits<int>::min()) <= longValue 
			&& longValue <= static_cast<long>(std::numeric_limits<int>::max())))
		return true;
	else
		return false;
}

