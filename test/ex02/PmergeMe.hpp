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
  template<typename Tkey, typename Tvalue, typename Tcontainer = std::vector<std::pair<Tkey, Tvalue > > >
  class unordered_map
  {};
  template<typename Tkey>
  class unordered_map<Tkey, std::deque<Tkey>, std::deque<std::pair<Tkey, std::deque<Tkey> > > >
  {
  public:
    unordered_map(void) : mMap() {}
    std::deque<Tkey>& operator[](Tkey key)
    {
      for (typename std::deque<std::pair<Tkey, std::deque<Tkey> > >::iterator it = mMap.begin(); it != mMap.end(); ++it)
      {
        if (it->first == key)
        {
          return it->second;
        }
      }
      mMap.push_back(std::pair<Tkey, std::deque<Tkey> >(key, std::deque<Tkey>()));
      return mMap.back().second;
    }
  private:
    std::deque<std::pair<Tkey, std::deque<Tkey> > > mMap;
  };
  template<typename Tkey>
  class unordered_map<Tkey, std::vector<Tkey>, std::vector<std::pair<Tkey, std::vector<Tkey> > > >
  {
  public:
    unordered_map(void) : mMap() {}
    std::vector<Tkey>& operator[](Tkey key)
    {
      for (typename std::vector<std::pair<Tkey, std::vector<Tkey> > >::iterator it = mMap.begin(); it != mMap.end(); ++it)
      {
        if (it->first == key)
        {
          return it->second;
        }
      }
      mMap.push_back(std::pair<Tkey, std::vector<Tkey> >(key, std::vector<Tkey>()));
      return mMap.back().second;
    }
  private:
    std::vector<std::pair<Tkey, std::vector<Tkey> > > mMap;
  };
private:
  PmergeMe& operator=(const PmergeMe& copy);
};

#endif