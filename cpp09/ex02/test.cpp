#include <vector>
#include <functional>
#include <map>
#include <algorithm>

// Comparator functor for size_t
/* struct Comparator {
    bool operator()(const size_t& lhs, const size_t& rhs) const {
        return lhs < rhs; // Change this line to customize the comparison logic
    }
}; */

size_t find_insert_point(size_t x, const std::vector<size_t>& xs)
{
    size_t lo = 0;
    size_t hi = xs.size();
    while (hi > lo)
    {
      size_t mid = lo + (hi - lo) / 2;
      if (x < xs[mid])
        hi = mid;
      else if (xs[mid] < x)
        lo = mid + 1;
      else
        return mid;
    }
    return lo;
}

void sort(std::vector<size_t>& xs)
{
  if (xs.size() < 2)
      return;

  std::map<size_t, std::vector<size_t> > partner;
  size_t half = xs.size() / 2;
  for (size_t i = 0; i < half; ++i)
  {
    if (xs[i] < xs[i + half])
        std::swap(xs[i], xs[i + half]);
    partner[xs[i]].push_back(xs[i + half]);
  }

  std::vector<size_t> first_half(xs.begin(), xs.begin() + half);
  sort(first_half);
  std::copy(first_half.begin(), first_half.end(), xs.begin());

  for (size_t i = 0; i < half; ++i)
  {
    size_t y = partner[xs[2 * i]].back();
    partner[xs[2 * i]].pop_back();
    size_t idx = find_insert_point(y, std::vector<size_t>(xs.begin(), xs.begin() + 2 * i));
    std::rotate(xs.begin() + idx, xs.begin() + half + i, xs.begin() + half + i + 1);
    xs[idx] = y;
  }
  if (xs.size() % 2 > 0)
  {
    size_t i = xs.size() - 1;
    size_t idx = find_insert_point(xs[i], std::vector<size_t>(xs.begin(), xs.begin() + i));
    std::rotate(xs.begin() + idx, xs.begin() + i, xs.end());
  }
}

#include <iostream>
#include <vector>
int main() {
    // Create a test vector of size_t
    std::vector<size_t> test_vector;
    test_vector.push_back(5);
    test_vector.push_back(3);
    test_vector.push_back(1);
    test_vector.push_back(4);
    test_vector.push_back(2);
    test_vector.push_back(2);
    test_vector.push_back(9);
    test_vector.push_back(9);
    for (int i = 0; i < 50; ++i)
    {
      test_vector.push_back(rand()%50);
    }
    // Print the original vector
    std::cout << "Original vector:" << std::endl;
    for (size_t i = 0; i < test_vector.size(); ++i) {
        std::cout << test_vector[i] << " ";
    }
    std::cout << std::endl;

    // Sort the vector
    
    sort(test_vector);

    // Print the sorted vector
    std::cout << "Sorted vector:" << std::endl;
    for (size_t i = 0; i < test_vector.size(); ++i) {
        std::cout << test_vector[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}