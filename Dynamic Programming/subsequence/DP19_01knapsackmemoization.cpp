//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int knapSack(int i, int W, vector<int> &val, vector<int> &wt, vector<vector<int> > &dp)
    {
        if (i == 0)
            return (wt[0] <= W) ? val[0] : 0;
        if (dp[i][W] != -1)
            return dp[i][W];

        int nottake = knapSack(i - 1, W, val, wt, dp);

        int take = 0;

        if (wt[i] <= W)
            take = val[i] + knapSack(i - 1, W - wt[i], val, wt, dp);

        return dp[i][W] = max(take, nottake);
    }

    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        vector<vector<int> > dp(val.size(), vector<int>(W + 1, -1));
        return knapSack(val.size() - 1, W, val, wt, dp);
    }
};