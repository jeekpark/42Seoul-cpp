#include <deque>
#include <functional>
#include "unordered_map.hpp"
#include <iostream>
int cmp = 0;
std::deque<size_t> getJacobsthalOrderdeque(size_t size)
{
  std::deque<size_t> res(size);
  for (size_t i = 1; i <= size; ++i) res[i - 1] = i;
  if (size == 1) return res;
  std::deque<size_t>::iterator start = res.begin() + 1, end = res.begin();
  for (size_t i = 2; end != res.end(); ++i)
  {
    size_t jacobsthalNumber = (pow(2, i + 1) + pow(-1, i)) / 3;
    while (*end != jacobsthalNumber && end != res.end()) ++end;
    std::reverse(start, end + (end == res.end() ? 0 : 1));
    start = end + (end == res.end() ? 0 : 1);
  }
  return res;
}

size_t find_insert_point(size_t x, const std::deque<size_t>& array)
{
  size_t left = 0, right = array.size();
  while (left < right)
  {cmp++;
    size_t mid = left + (right - left) / 2;
    if (array[mid] < x) left = mid + 1;
    else right = mid;
  }
  return left;
}

void sort(std::deque<size_t>& arr)
{
  if (arr.size() < 2) return;

  unordered_map<size_t, std::deque<size_t> , std::deque<std::pair<size_t, std::deque<size_t> > > > partner;
  size_t half = arr.size() / 2;
  for (size_t i = 0; i < half; ++i)
  {cmp++;
    if (arr[i] < arr[i + half]) std::swap(arr[i], arr[i + half]);
    partner[arr[i]].push_back(arr[i + half]);
  }

  std::deque<size_t> first_half(arr.begin(), arr.begin() + half);
  sort(first_half);

  std::copy(first_half.begin(), first_half.end(), arr.begin());
  std::deque<size_t> jacobsthalOrder = getJacobsthalOrderdeque(half);
  for (size_t i = 0; i < half; ++i)
  {
    size_t y = partner[arr[jacobsthalOrder[i] - 1]].back(); partner[arr[jacobsthalOrder[i] - 1]].pop_back();
    std::deque<size_t>::iterator it = first_half.begin();
    while (*it != arr[jacobsthalOrder[i] - 1]) ++it;
    size_t idx = 0;
    if (i != 0)
      idx = find_insert_point(y, std::deque<size_t>(first_half.begin(), it + 1));
    first_half.insert(first_half.begin() + idx, y);
  }
  if (arr.size() & 1)
  {
    size_t i = arr.size() - 1;
    size_t idx = find_insert_point(arr[i], first_half);
    first_half.insert(first_half.begin() + idx, arr[i]);
  }
  std::copy(first_half.begin(), first_half.end(), arr.begin());
}

#include <iostream>
int main()
{
  std::srand(static_cast<unsigned int>(std::time(0)));
  int  h = 0;
  while (1) 
  {
    std::deque<size_t> random_numbers;
    std::deque<size_t> copy;
    for (int i = 0; i < 56; ++i) 
        random_numbers.push_back(std::rand() % 100000 + 1);
    copy = random_numbers;
    sort(random_numbers);
    std::sort(copy.begin(), copy.end());
    if (cmp > 255)
    {
      if (h < cmp) h = cmp;
      std::cout << h - 255 << std::endl;
    }
    
    for (int i = 0; i < 56; ++i)
    {
      if (copy[i] != random_numbers[i])
        std::cout << "asdsadasd" << std::endl;
      if (copy.size() != random_numbers.size())
        std::cout << "asdasd" << std::endl;
    }
    cmp = 0;
  }
    return 0;
}
