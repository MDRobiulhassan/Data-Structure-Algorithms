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

int main() {
    Solution solution;
    std::vector<int> a = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    std::cout << "Original array: ";
    for (int num : a) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    solution.rotate(a, k);

    std::cout << "Rotated array: ";
    for (int num : a) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
