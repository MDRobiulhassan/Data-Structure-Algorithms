#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool subsetSum(int i, vector<int> &nums, int sum, vector<vector<int> > &dp)
    {
        if (sum == 0)
            return true;
        if (i == 0)
            return nums[0] == sum;
        if (dp[i][sum] != -1)
            return dp[i][sum];

        bool take = false;
        if (nums[i] <= sum)
            take = subsetSum(i - 1, nums, sum - nums[i], dp);
        bool nottake = subsetSum(i - 1, nums, sum, dp);

        return dp[i][sum] = take || nottake;
    }

    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        vector<vector<int> > dp(nums.size(), vector<int>(sum, -1));
        if (sum % 2 == 0)
            return subsetSum(nums.size() - 1, nums, sum / 2, dp);
        return false;
    }
};