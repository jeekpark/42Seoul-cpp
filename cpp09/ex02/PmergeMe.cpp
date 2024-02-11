/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 08:10:14 by jeekpark          #+#    #+#             */
/*   Updated: 2024/02/10 19:29:46 by jeekpark         ###   ########.fr       */
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

	//time_t dequeTimeTaken = sortByDeque();
	time_t listTimeTaken = sortByList();

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

void PmergeMe::printArgv() const
{
	for (int i = 1; i < mArgc; ++i)
		std::cout << mArgv[i] << " ";
}

void PmergeMe::printDeque() const
{
	for (std::deque<size_t>::const_iterator it = mDeque.begin();
			 it != mDeque.end(); ++it)
		std::cout << *it << " ";
}

size_t find_insert_point(size_t x, const std::list<size_t>& sequence)
{
	size_t lo = 0, hi = sequence.size();
	std::list<size_t>::const_iterator it = sequence.begin();
	while (hi > lo)
	{
		it = sequence.begin();
		size_t mid = lo + (hi - lo) / 2;
		for (size_t i = 0; i < mid; ++i)
			++it;
		if (x < *it) hi = mid;
		else if (*it < x) lo = mid + 1;
		else return mid;
	}
	return lo;
}

void PmergeMe::sort(std::list<size_t>& sequence)
{
  if (sequence.size() < 2) return ;

  unordered_map<size_t, std::list<size_t> > partner;
  size_t half = sequence.size() / 2;
  std::list<size_t>::iterator it_1 = sequence.begin();
  std::list<size_t>::iterator it_2 = sequence.begin();
  for (size_t i = 0; i < half; ++i)
    ++it_2;
  for (size_t i = 0; i < half; ++i)
  {
    if (*it_1 < *it_2)
      swap(*it_1, *it_2);
		partner[*it_1].push_back(*it_2);
		++it_1;
		++it_2;
  }
	
	std::list<size_t> firstHalf(sequence.begin(), it_1);
	sort(firstHalf);

	for (it_1 = firstHalf.begin(), it_2 = sequence.begin();
			 it_1 != firstHalf.end();
			 ++it_1, ++it_2)
		*it_2 = *it_1;
	for (size_t i = 0; i < half; ++i)
	{
		it_1 = sequence.begin();
		for (size_t j = 0; j < 2 * i; ++j)
			++it_1;
		size_t y = partner[*it_1].back(); partner[*it_1].pop_back();
		size_t idx = find_insert_point(y, std::list<size_t>(sequence.begin(), it_1));
		it_1 = sequence.begin();
		for (size_t j = 0; j < idx; ++j)
			++it_1; // 넣을 곳
		it_2 = sequence.begin();
		for (size_t j = 0; j < half + i; ++j)
			++it_2;
		sequence.splice(it_1, sequence, it_2);
		*it_2 = y;
	}

	if (sequence.size() & 1)
	{
		size_t i = sequence.size() - 1;
		size_t idx = find_insert_point(sequence.back(), std::list<size_t>(sequence.begin(), sequence.end()));
		it_1 = sequence.begin();
		for (size_t i = 0; i < idx; ++i)
			++it_1;
		it_2 = sequence.end();
		--it_2;
		sequence.splice(it_1, sequence, it_2);
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

void PmergeMe::swap(size_t& a, size_t& b)
{
	size_t c = a;
	a = b;
	b = c;
}
