#include <iostream>
#include <vector>
#include <algorithm>

void binaryInsertion(std::vector<int>& d, int start, int end, int value) {
    std::vector<int>::iterator it = std::lower_bound(d.begin()
                + start, d.begin() + end, value);
    d.insert(it, value);
}

std::vector<int> mergeInsertion(std::vector<int> d) {
    int n = d.size();
    if (n <= 1) return d;

    // Step 1: Pairwise comparison
    std::vector<int> a, b;
    for (int i = 0; i < n / 2; ++i) {
        a.push_back(std::max(d[i], d[i + n / 2]));
        b.push_back(std::min(d[i], d[i + n / 2]));
    }

    if (n % 2 == 1) {
        b.push_back(d[n - 1]);
    }

    // Step 2: Recursion and Renaming
    std::vector<std::pair<int, int> > m;
    for (int i = 0; i < static_cast<int>(b.size()); ++i) {
        m.push_back(std::make_pair(a[i], b[i]));
    }

    a = mergeInsertion(a); // Recursive call

    for (int i = 0; i < static_cast<int>(b.size()); ++i) {
        b[i] = m[i].second;
    }

    // Step 3: Insertion
    std::vector<int> result;
    result.push_back(b[0]);
    int k = 2;

    while (k - 1 < n / 2) {
        int tk = a[k - 1];
        int m = std::min(tk, n / 2);
        int u = tk - 1 + m;

        for (int i = m; i >= tk - 1; --i) {
            binaryInsertion(result, 0, u, b[i]);
            while (result[u] != a[i - 1]) {
                u--;
            }
        }
        k++;
    }

    // Adding the remaining elements from 'a' to the result
    for (size_t i = k - 1; i < a.size(); ++i) {
        result.push_back(a[i]);
    }

    return result;
}

int main() {
    std::vector<int> d; // Initialize with the elements to sort
    // Example: d.push_back(4); d.push_back(3); d.push_back(1); d.push_back(2);

    std::vector<int> sorted_d = mergeInsertion(d);

    // Print sorted array
    for (size_t i = 0; i < sorted_d.size(); ++i) {
        std::cout << sorted_d[i] << " ";
    }
    std::cout << std
