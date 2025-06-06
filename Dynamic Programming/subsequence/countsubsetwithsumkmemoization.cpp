#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int subsetSum(int i, vector<int> &arr, int target, vector<vector<int> > &dp)
    {
        if (i < 0)
            return (target == 0);
        if (dp[i][target] != -1)
            return dp[i][target];
        int take = 0;
        if (target >= arr[i])
            take = subsetSum(i - 1, arr, target - arr[i], dp);
        int nottake = subsetSum(i - 1, arr, target, dp);

        return dp[i][target] = take + nottake;
    }

    int perfectSum(vector<int> &arr, int target)
    {
        vector<vector<int> > dp(arr.size(), vector<int>(target + 1, -1));
        return subsetSum(arr.size() - 1, arr, target, dp);
    }
};