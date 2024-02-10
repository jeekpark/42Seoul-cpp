#include <list>
#include <functional>
#include <iostream>
#include "unordered_map.hpp"

size_t find_insert_point(size_t x, const std::list<size_t>& sequence)
{
    size_t lo = 0, hi = sequence.size();

    while (hi > lo)
    {
      size_t mid = lo + (hi - lo) / 2;
      if (x < sequence[mid]) hi = mid;
      else if (sequence[mid] < x) lo = mid + 1;
      else return mid;
    }
    return lo;
}

void sort(std::list<size_t>& sequence)
{
  if (sequence.size() < 2) return ;


}

#include <iostream>
int main() {


}
