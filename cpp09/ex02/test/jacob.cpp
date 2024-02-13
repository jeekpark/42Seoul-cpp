#include <algorithm>
#include <iostream>

#include <cmath>
#include <sys/_types/_size_t.h>
#include <vector>

using namespace std;

// 0 -> 1
// 1 -> 1
// 2 -> 3
// 3 -> 5
// 4 -> 11

/**
 * @brief Get the Jacobsthal number
 *
 * n -> return 
 * 0 -> 1
 * 1 -> 1
 * 2 -> 3
 * 3 -> 5
 * 4 -> 11
 *
 * @param n order
 * @return size_t Jacobsthal number
 */
size_t getJacobsthalNumber(size_t n)
{
    return (pow(2, n + 1) + pow(-1, n)) / 3;
}

/**
 * @brief Get the Jacobsthal Order object
 * 
 * 10 -> 1 (3 2) (5 4) (10 9 8 7 6)
 *
 * @param size 
 * @return std::vector<size_t> Jacobsthal order array
 */
std::vector<size_t> getJacobsthalOrder(size_t size)
{
    std::vector<size_t> res(size);
    for (size_t i = 1; i <= size; ++i) res[i - 1] = i;
    if (size == 1) return res;
    std::vector<size_t>::iterator start = res.begin() + 1, end = res.begin();
    for (size_t i = 2; end != res.end(); ++i)
    {
        while (*end != getJacobsthalNumber(i) && end != res.end()) ++end;
        std::reverse(start, end + (end == res.end() ? 0 : 1));
        start = end + (end == res.end() ? 0 : 1);
    }
    return res;
}

int main()
{
    int size = 5;
    std::vector<size_t> a = getJacobsthalOrder(size);

    for (int i = 0; i < size; ++i)
    {
        cout << a[i] << endl;
    }

}