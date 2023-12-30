/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 08:10:14 by jeekpark          #+#    #+#             */
/*   Updated: 2023/12/30 10:34:11 by jeekpark         ###   ########.fr       */
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

	time_t dequeTimeTaken = sortDeque();
	time_t listTimeTaken = sortList();

	std::cout << "Before:\t";
	printArgv();
	std::cout << "\nAfter:\t";
	printDeque();
	std::cout << "\nTime to process a range of "
						<< mArgc - 1
						<< " elements with std::deque : "
						<< static_cast<unsigned long>(dequeTimeTaken)
						<< " ms"
						<< std::endl;
	std::cout << "Time to process a range of "
						<< mArgc - 1
						<< " elements with std::list : "
						<< static_cast<unsigned long>(listTimeTaken)
						<< " ms"
						<< std::endl;
	return true;
}

bool compare(int a, int b)
{
	return a < b;
}

time_t PmergeMe::sortDeque()
{
	clock_t start, end;
	start = clock();

	for (int i = 1; i < mArgc; ++i)
	{
		mDeque.push_back(std::atoi(mArgv[i]));
	}

	sort(mDeque, compare);

	end = clock();
	return end - start;
}

void		PmergeMe::sort(std::deque<int>& xs, Compare cmp)
{
	if (xs.size() < 2)
		return ;

	std::map<int, std::deque<int> > partner;
	int half = xs.size() / 2;
	for (int i = 0; i < half; ++i)
	{
		if (i + half < static_cast<int>(xs.size()) && cmp(xs[i], xs[i + half]))
		{
			std::swap(xs[i], xs[i + half]);
		}
		if (i + half < static_cast<int>(xs.size()))
			partner[xs[i]].push_back(xs[i + half]);
	}

	std::deque<int> firstHalf(xs.begin(), xs.begin() + half);
	sort(firstHalf, cmp);
	std::copy(firstHalf.begin(), firstHalf.end(), xs.begin());

	for (int i = 0; i < half; ++i)
	{
		if (partner.find(xs[2 * i]) != partner.end() && !partner[xs[2 * i]].empty())
		{
			int y = partner[xs[2 * i]].back();
			partner[xs[2 * i]].pop_back();
			int idx = 0;
			while (idx < 2 * i && idx < static_cast<int>(xs.size()) && !cmp(y, xs[idx]))
				++idx;
			if (idx <= static_cast<int>(xs.size()))
				xs.insert(xs.begin() + idx, y);
		}
	}
	if (xs.size() % 2 > 0)
	{
		int i = xs.size() - 1;
		int idx = 0;
		while (idx < i && !cmp(xs[i], xs[idx]))
			++idx;
		if (!xs.empty()) {
				int y = xs.back();
				xs.pop_back();
				if (idx <= static_cast<int>(xs.size())) {
						xs.insert(xs.begin() + idx, y);
				}
		}
	}
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

