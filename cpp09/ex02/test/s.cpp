
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);

    std::vector<int> copy = a;

    std::rotate(a.begin(), a.begin() + 2, a.end());

    for (int i = 0; i < 5; ++i)
    {
        std::cout << copy[i] << ":" << a[i] << std::endl;
    }
}