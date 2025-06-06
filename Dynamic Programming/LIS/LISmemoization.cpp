#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int LIS(int i, int prev_i, vector<int> &nums, vector<vector<int> > &dp)
    {
        if (i == nums.size())
            return 0;

        //to handle the -1 of prev_i we shift the coordintate to 1 right
        if (dp[i][prev_i + 1] != -1)
            return dp[i][prev_i + 1];

        // nottake
        int len = LIS(i + 1, prev_i, nums, dp);
        
        // take
        if (prev_i == -1 || nums[i] > nums[prev_i])  //i=current index and prev_i = previous index that is included in the sequence
            len = max(len, 1 + LIS(i + 1, i, nums, dp));

        return dp[i][prev_i + 1] = len;
    }

    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int> > dp(n, vector<int>(n, -1));
        return LIS(0, -1, nums, dp);
    }
};