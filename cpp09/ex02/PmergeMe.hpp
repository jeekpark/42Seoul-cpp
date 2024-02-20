#pragma once
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <vector>
#include <iostream>
#include <ctime>
#include <cmath>
#include <utility>
#include <algorithm>
#include <limits>

#include "unordered_map.hpp"

class PmergeMe
{
public:
  PmergeMe(const int argc, const char**argv);
  PmergeMe(const PmergeMe& copy);
  ~PmergeMe();
public:
  bool run();

private:
  size_t findInsertPoint(size_t x, const std::deque<size_t>& sequence);
  size_t findInsertPoint(size_t x, const std::vector<size_t>& sequence);
  void sort(std::deque<size_t>& sequence);
  void sort(std::vector<size_t>& sequence);
private:
  void printArgv() const;
  void printDeque() const;
  bool isInt(const std::string& literal) const;
  std::vector<size_t> getJacobsthalOrderVector(size_t size);
  std::deque<size_t> getJacobsthalOrderDeque(size_t size);
private:
  const int mArgc;
  const char** mArgv;
  std::deque<size_t> mSequenceDeque;
  std::vector<size_t> mSequenceVector; 
private:
  PmergeMe& operator=(const PmergeMe& copy);
};

#endif