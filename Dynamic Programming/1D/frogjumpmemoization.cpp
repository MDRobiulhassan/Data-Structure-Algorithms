//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int pathCost(int i, vector<int> &height, vector<int> &dp)
    {
        if (i == 0)
            return 0;
        if (dp[i] != -1)
            return dp[i];

        int l = INT_MAX;
        int r = INT_MAX;

        l = pathCost(i - 1, height, dp) + abs(height[i] - height[i - 1]);
        if (i > 1)
            r = pathCost(i - 2, height, dp) + abs(height[i] - height[i - 2]);
        return dp[i] = min(l, r);
    }

    int minCost(vector<int> &height)
    {
        int n = height.size();
        vector<int> dp(n + 1, -1);
        return pathCost(n - 1, height, dp);
    }
};