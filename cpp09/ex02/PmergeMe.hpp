/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:44:14 by jeekpark          #+#    #+#             */
/*   Updated: 2023/12/30 10:17:38 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <list>
#include <cstdlib>
#include <unordered_map>
#include <iostream>
#include <ctime>
#include <map>

class PmergeMe
{
public: // OCF
	PmergeMe(const int argc, const char**argv);
	PmergeMe(const PmergeMe& copy);
	~PmergeMe();
private: // OCF: no uses
	PmergeMe& operator=(const PmergeMe& copy);

public: // basic function
	bool sort(); // returns success or failure




private: // basic(priv) function

	time_t	sortDeque(); // returns time taken
	void		sortDequeFJ(std::deque<int>& dq);
	size_t	findInsertPoint(int x, const std::deque<int>& dq);

	time_t	sortVector(); // returns time taken
	void		sortVectorFJ(std::list<int>& lst);

	
	
	
private: // utils
	void	printArgv() const;
	void	printDeque() const;
	bool	isInt(const std::string& literal) const;


private: // const vars
	const int				mArgc;
	const char**		mArgv;

private: // general vars
	std::deque<int>	mDeque;
	std::vector<int>	mVector;
};

#endif