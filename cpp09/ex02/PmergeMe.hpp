/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:44:14 by jeekpark          #+#    #+#             */
/*   Updated: 2024/02/10 19:28:39 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <list>
#include <cstdlib>
#include <iostream>
#include <ctime>


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

  time_t sortByList(); // returns time taken
  time_t sortByDeque(); // returns time taken
  void sort(std::list<size_t>& arr);

private: // utils
  void printArgv() const;
  void printDeque() const;
  bool isInt(const std::string& literal) const;
  void swap(int& a, int& b);

private: // const vars
  const int mArgc;
  const char** mArgv;

private: // general vars
  std::deque<size_t>	mDeque;
  std::list<size_t>	mList;
};

#endif