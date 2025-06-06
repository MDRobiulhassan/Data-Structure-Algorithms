//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int minimizeCost(int k, vector<int> &arr)
    {
        int n = arr.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                if (i - j >= 0)
                    dp[i] = min(dp[i], dp[i - j] + abs(arr[i] - arr[i - j]));
            }
        }
        return dp[n - 1];
    }
};