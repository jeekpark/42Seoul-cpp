#include <cstdlib>
#include <cmath>
#include <iostream>

#include <vector>
#include <algorithm>

void binaryInsertion(std::vector<int>& d, int start, int end, int x) {
    int left = start;
    int right = end - 1;
    int mid;

    while (left <= right) {
        mid = left + (right - left) / 2;
        if (d[mid] < x) left = mid + 1;
        else right = mid - 1;
    }

    d.insert(d.begin() + left, x);
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

void mergeInsertion(std::vector<int>& d) {
    int n = d.size();
    if (n < 2) return;

    std::vector<int> a;
    std::vector<int> b;
    for (int i = 0; i < n / 2; ++i)
    {
      a.push_back(std::max(d[i], d[i + std::ceil((float)n / 2)]));
      b.push_back(std::min(d[i], d[i + std::ceil((float)n / 2)]));
    }
    if (n & 1)
      b.push_back(d[n / 2]);

    // ^ line: 9

    mergeInsertion(a);
    
    printVector(a);
    printVector(b);

}


int main()
{
  std::vector<int> d;

  /* for (int i = 20; i > 0; --i)
  {
    d.push_back(random() % 20);
  } */
  d.push_back(4); // 4 2 5 1 3 7
  d.push_back(2);
  d.push_back(5);
  d.push_back(1);
  d.push_back(3);
  //d.push_back(7);


  std::cout << "fin " << std::endl;


  mergeInsertion(d);

  /* for (size_t i = 0; i < d.size(); ++i) {
      std::cout << d[i] << " ";
  } */
  std::cout << std::endl;
}