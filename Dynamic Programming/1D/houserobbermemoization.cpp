#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int subsetsum(int i, vector<int> &nums, vector<int> &dp)
    {
        if (i == 0)
            return nums[i];
        if (i < 0)
            return 0;
        if (dp[i] != -1)
            return dp[i];

        return dp[i] = max(nums[i] + subsetsum(i - 2, nums, dp), 0 + subsetsum(i - 1, nums, dp));
    }
    int rob(vector<int> &nums)
    {
        vector<int> dp(nums.size(), -1);
        return subsetsum(nums.size() - 1, nums, dp);
    }
};