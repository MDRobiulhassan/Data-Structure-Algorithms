#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int subsetsum(int i, vector<int> &nums)
    {
        if (i == 0)
            return nums[i];
        if (i < 0)
            return 0;

        int pick = nums[i] + subsetsum(i - 2, nums);
        int notpick = 0 + subsetsum(i - 1, nums);

        return max(pick, notpick);
    }
    int rob(vector<int> &nums)
    {
        return subsetsum(nums.size() - 1, nums);
    }
};