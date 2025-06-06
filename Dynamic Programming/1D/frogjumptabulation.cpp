//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int pathCost(vector<int> &height, vector<int> &dp)
    {
        dp[0] = 0;

        for (int i = 1; i < height.size(); i++)
        {
            int l = dp[i - 1] + abs(height[i] - height[i - 1]);
            int r = INT_MAX;
            if (i > 1)
                r = dp[i - 2] + abs(height[i] - height[i - 2]);
            dp[i] = min(l, r);
        }
        return dp[height.size() - 1];
    }

    int minCost(vector<int> &height)
    {
        int n = height.size();
        vector<int> dp(n, 0);

        return pathCost(height, dp);
    }
};