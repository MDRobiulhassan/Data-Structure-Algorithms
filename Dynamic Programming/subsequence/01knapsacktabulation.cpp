//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution
{
public:
    int knapSack(vector<int> &val, vector<int> &wt, int capacity)
    {
        int n = val.size();
        vector<vector<int> > dp(n, vector<int>(capacity + 1, 0));

        for (int i = 0; i <= capacity; i++)
            dp[0][i] = val[0] * (i / wt[0]);

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= capacity; j++)
            {
                int nottake = dp[i - 1][j];
                int take = 0;
                if (wt[i] <= j)
                    take = val[i] + dp[i][j - wt[i]];

                dp[i][j] = max(take, nottake);
            }
        }
        return dp[n - 1][capacity];
    }
};