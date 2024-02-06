#include <vector>


size_t find_insert_point(size_t x, const std::vector<int>& arr)
{
  size_t lo = 0;
  size_t hi = arr.size();
  while (hi > lo)
  {
    size_t mid  = lo + (hi - lo) / 2;
    if (x < arr[mid])
      hi = mid;
    else if (arr[mid] < x)
      lo = mid + 1;
    else
      return mid;
  }
  return lo;
}

#include <map>
void sort(std::vector<int>& arr)
{
  if (arr.size() < 2)
    return ;

  bool odd = false;
  int num;
  if (arr.size() & 1)
  {
    odd = true;
    num = arr.back();
    arr.pop_back();
  }

  std::vector<std::pair<int, int> > pairs;
  pairs.reserve(arr.size() / 2);
  for (size_t i = 0; i < arr.size(); i += 2)
  {
    if (pairs[i].first < pair)
  }


  std::map<int, std::vector<int> > partner;
  size_t half = arr.size() / 2;
  for (size_t i = 0; i < half; ++i)
  {
    if (arr[i] < arr[i + half])
      std::swap(arr[i], arr[i + half]);
    partner[arr[i]].push_back((arr[i + half]));
  }

  std::vector<int> first_half
}