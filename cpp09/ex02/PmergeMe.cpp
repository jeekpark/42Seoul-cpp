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


PmergeMe::PmergeMe(const int argc, const char** argv)
: mArgc(argc)
, mArgv(argv)
{}

PmergeMe::PmergeMe(const PmergeMe& copy)
: mArgc(copy.mArgc)
, mArgv(copy.mArgv)
, mDeque(copy.mDeque)
, mVector(copy.mVector)
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
	time_t listTimeTaken = sortVector();

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



time_t PmergeMe::sortDeque()
{
	clock_t start, end;
	start = clock();

	for (int i = 1; i < mArgc; ++i)
	{
		mDeque.push_back(std::atoi(mArgv[i]));
	}

	sortDequeFJ(mDeque);
	end = clock();
	return end - start;
}
size_t PmergeMe::findInsertPoint(int x, const std::deque<int>& dq)
{
    size_t lo = 0;
    size_t hi = dq.size();
    while (hi > lo)
    {
      size_t mid = lo + (hi - lo) / 2;
      if (x < dq[mid])
        hi = mid;
      else if (dq[mid] < x)
        lo = mid + 1;
      else
        return mid;
    }
    return lo;
}
void PmergeMe::sortDequeFJ(std::deque<int>& dq)
{
	if (dq.size() < 2)
		return ;
	std::map<int, std::deque<int> > partner;
	size_t half = dq.size() / 2;
	for (size_t i = 0; i < half; ++i)
	{
		if (dq[i] < dq[i + half])
			std::swap(dq[i], dq[i + half]);
		partner[dq[i]].push_back(dq[i + half]);
	}

	std::deque<int> firstHalf(dq.begin(), dq.begin() + half);
	sortDequeFJ(firstHalf);
	std::copy(firstHalf.begin(), firstHalf.end(), dq.begin());

	for (size_t i = 0; i < half; ++i)
  {
    int y = partner[dq[2 * i]].back();
    partner[dq[2 * i]].pop_back();
    size_t idx = findInsertPoint(y, std::deque<int>(dq.begin(), dq.begin() + 2 * i));
    std::rotate(dq.begin() + idx, dq.begin() + half + i, dq.begin() + half + i + 1);
    dq[idx] = y;
  }
  if (dq.size() % 2 > 0)
  {
    size_t i = dq.size() - 1;
    size_t idx = findInsertPoint(dq[i], std::deque<int>(dq.begin(), dq.begin() + i));
    std::rotate(dq.begin() + idx, dq.begin() + i, dq.end());
  }
}

time_t PmergeMe::sortList()
{
	clock_t start, end;
	start = clock();

	for (int i = 1; i < mArgc; ++i)
	{
		mList.push_back(std::atoi(mArgv[i]));
	}

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

