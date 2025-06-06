#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool subsetSum(int i, vector<int> &nums, int sum)
    {
        if (sum == 0)
            return true;
        if (i == 0)
            return nums[0] == sum;

        bool take = false;
        if (nums[i] <= sum)
            take = subsetSum(i - 1, nums, sum - nums[i]);
        bool nottake = subsetSum(i - 1, nums, sum);

        return take || nottake;
    }

    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        if (sum % 2 == 0)
            return subsetSum(nums.size() - 1, nums, ceil(double(sum) / 2));
        return false;
    }
};