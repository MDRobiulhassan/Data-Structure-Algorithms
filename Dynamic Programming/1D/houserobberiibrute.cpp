#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int withoutfirst(int i, vector<int> &nums)
    {
        if (i == 1)
            return nums[i];
        if (i <= 0)
            return 0;

        int pick = nums[i] + withoutfirst(i - 2, nums);
        int notpick = 0 + withoutfirst(i - 1, nums);
        return max(pick, notpick);
    }

    int withoutlast(int i, vector<int> &nums)
    {
        if (i == 0)
            return nums[i];
        if (i < 0)
            return 0;

        int pick = nums[i] + withoutlast(i - 2, nums);
        int notpick = 0 + withoutlast(i - 1, nums);
        return max(pick, notpick);
    }

    int subsetsum(vector<int> &nums)
    {
        int ans1 = withoutfirst(nums.size() - 1, nums);
        int ans2 = 0;
        if (nums.size() > 1)
            ans2 = withoutlast(nums.size() - 2, nums);
        return max(ans1, ans2);
    }
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        return subsetsum(nums);
    }
};