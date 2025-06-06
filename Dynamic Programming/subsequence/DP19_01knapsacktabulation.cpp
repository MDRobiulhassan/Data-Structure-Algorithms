//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        int n = val.size();
        vector<vector<int> > dp(n, vector<int>(W + 1, 0));
        for (int i = wt[0]; i <= W; i++)
            dp[0][i] = val[0];

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= W; j++)
            {
                int nottake = dp[i - 1][j];

                int take = 0;

                if (wt[i] <= j)
                    take = val[i] + dp[i - 1][j - wt[i]];

                dp[i][j] = max(take, nottake);
            }
        }
        return dp[n - 1][W];
    }
};