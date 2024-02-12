#include <algorithm>
#include <iostream>

#include <cmath>
#include <sys/_types/_size_t.h>
#include <vector>

using namespace std;

/**
 * @brief It rearranges index numbers by jacobsthal numbers
 * 
 * @param n normal index
 * @return size_t optimal index
 */

size_t j(size_t n)
// 0 -> 1
// 1 -> 1
// 2 -> 3
// 3 -> 5
// 4 -> 11
{
    return (pow(2, n + 1) + pow(-1, n)) / 3;
}

std::vector<size_t> optIndexArr(size_t size) // 10 -> 1 (3 2) (5 4) (10 9 8 7 6)
{
    const size_t maxIndex = size; // maxIndex -> 10

    std::vector<size_t> res(size);

    for (size_t i = 1; i <= size; ++i)
        res[i - 1] = i;
    
    if (size == 1)
        return res;

    std::vector<size_t>::iterator start = res.begin();
    std::vector<size_t>::iterator end = res.begin();
    size_t jNum = 2;
    for (;;)
    {
        ++start;
        while (end != res.end() && j(jNum) != *end)
            end++;
        if (end == res.end())
        {
            std::reverse(start, end);
            return res;
        }
        //cout << *start <<  " " << *end << endl;
        std::reverse(start, end+1);
        start = end + 1;
        jNum++;
        
    }
    return res;
}

int main()
{
    std::vector<size_t> a = optIndexArr(10);

    for (int i = 0; i < 10; ++i)
    {
        cout << a[i] << endl;
    }

}