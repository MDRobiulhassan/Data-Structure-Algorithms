#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int LIS(int i, int prev_i, vector<int> &nums)
    {
        if (i == nums.size())
            return 0;

        //nottake
        int len = LIS(i + 1, prev_i, nums);

        //take
        if (prev_i == -1 || nums[i] > nums[prev_i])
            len = max(len, 1 + LIS(i + 1, i, nums));

        return len;
    }

    int lengthOfLIS(vector<int> &nums) { return LIS(0, -1, nums); }
};