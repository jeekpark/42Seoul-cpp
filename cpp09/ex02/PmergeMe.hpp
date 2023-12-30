/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:44:14 by jeekpark          #+#    #+#             */
/*   Updated: 2023/12/30 09:38:58 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <list>
#include <unordered_map>
#include <iostream>
#include <ctime>

class PmergeMe
{
public: // OCF
	PmergeMe(const int argc, const char**argv);
	PmergeMe(const PmergeMe& copy);
	~PmergeMe();

public: // basic function
	bool sort(); // returns success or failure


//----------------------------------------------------------------------------//
// private functions
private: // basic(priv) function
	time_t sortDeque(); // returns time taken
	time_t sortList(); // returns time taken

private: // utils
	void	printArgv() const;
	void	printDeque() const;
	bool	isInt(const std::string& literal) const;

private: // no uses
	PmergeMe& operator=(const PmergeMe& copy);

//----------------------------------------------------------------------------//
// private vars
private: // const vars
	const int				mArgc;
	const char**		mArgv;

private: // general vars
	std::deque<int>	mDeque;
	std::list<int>	mList;
};

#endif