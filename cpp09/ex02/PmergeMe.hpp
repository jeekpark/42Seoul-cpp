/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:44:14 by jeekpark          #+#    #+#             */
/*   Updated: 2023/12/30 08:09:23 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <list>
#include <unordered_map>

class PmergeMe
{
public: // OCF
	PmergeMe();
	PmergeMe(const PmergeMe& copy);
	~PmergeMe();
	PmergeMe& operator=(const PmergeMe& copy);

public: // basic function
	void pushElement(int num);
	void sortDeque();
	void sortList();
	
public: // getter function
	const std::deque<int>& getDeque() const;
	const std::list<int>& getList() const;
	const float& getDequeTimeTaken() const;
	const float& getListTimeTaken() const;

private:
	std::deque<int>	mDeque;
	std::list<int>	mlist;
	float						mDequeTimeTaken;
	float						mListTimeTaken;
};

#endif