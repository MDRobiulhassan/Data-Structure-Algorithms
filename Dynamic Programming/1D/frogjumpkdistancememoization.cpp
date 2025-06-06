//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int findPath(int i, int k, vector<int> &arr, vector<int> &dp)
    {
        if (i == 0)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int ans = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
                ans = min(ans, findPath(i - j, k, arr, dp) + abs(arr[i] - arr[i - j]));
        }
        return dp[i] = ans;
    }

    int minimizeCost(int k, vector<int> &arr)
    {
        int n = arr.size();
        vector<int> dp(n + 1, -1);
        return findPath(n - 1, k, arr, dp);
    }
};