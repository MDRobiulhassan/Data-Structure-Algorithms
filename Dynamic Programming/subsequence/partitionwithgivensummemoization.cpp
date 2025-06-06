#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int subsetSum(int i, vector<int> &arr, int target, vector<vector<int> > &dp)
    {
        if (i < 0)
            return target == 0;
        if (dp[i][target] != -1)
            return dp[i][target];

        int nottake = subsetSum(i - 1, arr, target, dp);
        int take = 0;
        if (arr[i] <= target)
            take = subsetSum(i - 1, arr, target - arr[i], dp);

        return dp[i][target] = take + nottake;
    }

    int countPartitions(vector<int> &arr, int d)
    {
        int total = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++)
            total += arr[i];

        if (total - d < 0 || (total - d) % 2 != 0)
            return false;
        int target = (total - d) / 2;
        vector<vector<int> > dp(n, vector<int>(target + 1, -1));
        return subsetSum(n - 1, arr, target, dp);
    }
};