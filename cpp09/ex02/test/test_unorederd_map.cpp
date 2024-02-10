#include "unordered_map.hpp"


#include <vector>
#include <functional>

#include <iostream>

size_t find_insert_point(size_t x, const std::vector<size_t>& array)
{
    size_t lo = 0, hi = array.size();
    while (hi > lo)
    {
      size_t mid = lo + (hi - lo) / 2;
      if (x < array[mid]) hi = mid;
      else if (array[mid] < x) lo = mid + 1;
      else return mid;
    }
    return lo;
}

void sort(std::vector<size_t>& arr)
{
  if (arr.size() < 2) return;

  unordered_map<size_t, std::list<size_t>, std::list<std::pair<size_t, std::list<size_t> > > > partner;
  size_t half = arr.size() / 2;
  for (size_t i = 0; i < half; ++i)
  {
    if (arr[i] < arr[i + half])
      std::swap(arr[i], arr[i + half]);
    partner[arr[i]].push_back(arr[i + half]);
  }

  std::vector<size_t> first_half(arr.begin(), arr.begin() + half);
  sort(first_half);

  std::copy(first_half.begin(), first_half.end(), arr.begin());
  for (size_t i = 0; i < half; ++i)
  {
    size_t y = partner[arr[2 * i]].back(); partner[arr[2 * i]].pop_back();
    size_t idx = find_insert_point(y, std::vector<size_t>(arr.begin(), arr.begin() + 2 * i));
    std::rotate(arr.begin() + idx, arr.begin() + half + i, arr.begin() + half + i + 1);
    arr[idx] = y;
  }
  
  if (arr.size() & 1)
  {
    size_t i = arr.size() - 1;
    size_t idx = find_insert_point(arr[i], std::vector<size_t>(arr.begin(), arr.begin() + i));
    std::rotate(arr.begin() + idx, arr.begin() + i, arr.end());
  }
}

#include <iostream>
#include <vector>
int main() {

    std::vector<size_t> test_vector;
    test_vector.push_back(0);
    test_vector.push_back(20);
    test_vector.push_back(7);
    test_vector.push_back(1);
    test_vector.push_back(30);
    test_vector.push_back(5);
    test_vector.push_back(8);
    test_vector.push_back(15);
    test_vector.push_back(18);
    std::cout << "Original vector:" << std::endl;
    for (size_t i = 0; i < test_vector.size(); ++i)
        std::cout << test_vector[i] << " ";
    std::cout << std::endl;
    
    sort(test_vector);

    std::cout << "Sorted vector:" << std::endl;
    for (size_t i = 0; i < test_vector.size(); ++i)
        std::cout << test_vector[i] << " ";
    std::cout << std::endl;

    return 0;
}
