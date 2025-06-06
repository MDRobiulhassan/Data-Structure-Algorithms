#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool subsetSum(int i, vector<int> &arr, int target, vector<vector<int> > &dp)
    {
        if (target == 0)
            return true;
        if (i == 0)
            return arr[0] == target;
        if (dp[i][target] != -1)
            return dp[i][target];

        bool nottake = subsetSum(i - 1, arr, target, dp);
        bool take = false;
        if (arr[i] <= target)
            take = subsetSum(i - 1, arr, target - arr[i], dp);

        return dp[i][target] = take || nottake;
    }

    bool isSubsetSum(vector<int> &arr, int target)
    {
        vector<vector<int> > dp(arr.size(), vector<int>(target + 1, -1));
        return subsetSum(arr.size() - 1, arr, target, dp);
    }
};