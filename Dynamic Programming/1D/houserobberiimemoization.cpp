#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int withoutfirst(int i, vector<int> &nums, vector<int> &dp)
    {
        if (i == 1)
            return nums[i];
        if (i <= 0)
            return 0;
        if (dp[i] != -1)
            return dp[i];

        int pick = nums[i] + withoutfirst(i - 2, nums, dp);
        int notpick = 0 + withoutfirst(i - 1, nums, dp);
        return dp[i] = max(pick, notpick);
    }

    int withoutlast(int i, vector<int> &nums, vector<int> &dp)
    {
        if (i == 0)
            return nums[i];
        if (i < 0)
            return 0;
        if (dp[i] != -1)
            return dp[i];

        int pick = nums[i] + withoutlast(i - 2, nums, dp);
        int notpick = 0 + withoutlast(i - 1, nums, dp);
        return dp[i] = max(pick, notpick);
    }

    int subsetsum(vector<int> &nums)
    {
        vector<int> dp1(nums.size(), -1);
        int ans1 = withoutfirst(nums.size() - 1, nums, dp1);
        int ans2 = 0;
        vector<int> dp2(nums.size(), -1);
        if (nums.size() > 1)
            ans2 = withoutlast(nums.size() - 2, nums, dp2);
        return max(ans1, ans2);
    }
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        return subsetsum(nums);
    }
};