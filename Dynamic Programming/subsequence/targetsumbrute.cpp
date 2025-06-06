#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int subsetSum(int i, vector<int> &nums, int target)
    {
        if (i < 0)
        {
            if (target == 0)
                return 1;
            return 0;
        }

        int plus = subsetSum(i - 1, nums, target - nums[i]);
        int minus = subsetSum(i - 1, nums, target + nums[i]);

        return plus + minus;
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        return subsetSum(n - 1, nums, target);
    }
};