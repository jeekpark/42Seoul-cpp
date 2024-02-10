#include <cstdlib>
#include <cmath>
#include <iostream>

#include <unordered_map>
#include <vector>
#include <algorithm>

size_t find_insert_point(int x,
                         std::vector<int>::iterator start,
                         std::vector<int>::iterator end)
{
  size_t lo = 0;
  size_t hi = end - start;
  while (hi > lo)
  {
    size_t mid = lo + (hi - lo) / 2;
    if (x < *(start + mid))
      hi = mid;
    else if (*(start + mid) < x)
      lo = mid + 1;
    else
      return mid;
  }
  return lo;
}

void printVector(std::vector<int>& v)
{
  std::cout << "\n----start----\n";
  for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
  {
    std::cout << *it << "\n";
  }
  std::cout << "-----end-----" << std::endl;
}

void mergeInsertion(std::vector<int>::iterator start, std::vector<int>::iterator end) {
  int n = end - start;
  if (n < 2) return;

  std::unordered_map<int, std::vector<int> > partner;
  
  // large numbers comes to front.
  for (int i = 0; i < n / 2; ++i)
  {
    if (*(start + i) < *(start + i + std::ceil((float)n / 2)))
    {
      int temp = *(start + i);
      *(start + i) = *(start + i + std::ceil((float)n / 2));
      *(start + i + std::ceil((float)n / 2)) = temp;
    }
    partner[*(start + i)].push_back( *(start + i + std::ceil((float)n / 2)));
  }
  if (n & 1)
    partner[*(start + n / 2)].clear();

  mergeInsertion(start, start + n / 2 );

  std::vector<int> a(start, end);
  printVector(a);
  for (int i = 0; i < n / 2; ++i)
  {
    int y = partner[*(start + (2 * i))].back();
    partner[*(start + (2 * i))].pop_back();
    size_t idx = find_insert_point(y, start, start + (2 * i));
    std::rotate(start + idx, start + i, end);
  }
  if (n % 2 > 0)
  {
    size_t i = n - 1;
    size_t idx = find_insert_point(*(start + i), start, start + i);
    std::rotate(start + idx, start + i, end);
  }

  std::vector<int> b(start, end);
  printVector(b);
}







int main()
{
  std::vector<int> d;

  /* for (int i = 20; i > 0; --i)
  {
    d.push_back(random() % 20);
  } */
  d.push_back(4); // 4 2 7 1 3 5 0 6
  d.push_back(2);
  d.push_back(7);
  d.push_back(1);
  d.push_back(3);
  d.push_back(5);
  d.push_back(0);
  d.push_back(6);




  mergeInsertion(d.begin(), d.end());
  printVector(d);
  std::cout << std::endl;
}