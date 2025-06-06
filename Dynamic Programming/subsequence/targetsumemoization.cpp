#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int subsetSum(int i, vector<int> &nums, int target,
                  map<int, map<int, int> > &dp)
    {
        if (i < 0)
        {
            return target == 0;
        }

        if (dp[i].count(target))
            return dp[i][target];

        int plus = subsetSum(i - 1, nums, target - nums[i], dp);
        int minus = subsetSum(i - 1, nums, target + nums[i], dp);

        return dp[i][target] = plus + minus;
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        map<int, map<int, int> > dp;
        return subsetSum(n - 1, nums, target, dp);
    }
};