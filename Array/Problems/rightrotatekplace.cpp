#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    void rotate(std::vector<int>& a, int k) {
        int n = a.size();
        k = k % n; // In case k is larger than n
        std::reverse(a.begin(), a.end());
        std::reverse(a.begin() + k, a.end());
        std::reverse(a.begin(), a.begin() + k);
    }
};
