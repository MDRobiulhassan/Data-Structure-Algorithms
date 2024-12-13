#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        if (a.empty()) return 0;  // Edge case: empty vector

        int j = 0;
        for (int i = 1; i < a.size(); i++) {
            if (a[i] != a[j]) {
                j++;
                a[j] = a[i];
            }
        }
        return j + 1;
    }
};

int main() {
    Solution solution;
    vector<int> nums ;
    //input

    int newSize = solution.removeDuplicates(nums);

    cout << "New size of array after removing duplicates: " << newSize << endl;
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newSize; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
