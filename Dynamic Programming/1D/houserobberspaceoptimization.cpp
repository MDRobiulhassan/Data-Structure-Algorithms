#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        vector<int> dp(nums.size(), -1);
        if (nums.size() == 1)
            return nums[0];
        int prev2 = nums[0];
        int prev = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++)
        {
            int curi = max(nums[i] + prev2, 0 + prev);
            prev2 = prev;
            prev = curi;
        }

        return prev;
    }
};