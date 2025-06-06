//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution
{
public:
    int cutRod(vector<int> &price)
    {
        int n = price.size();
        vector<vector<int> > dp(n, vector<int>(n + 1, 0));
        for (int i = 0; i <= n; i++)
            dp[0][i] = price[0] * i;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                int nottake = dp[i - 1][j];

                int take = 0;
                if (i + 1 <= j)
                    take = price[i] + dp[i][j - (i + 1)];

                dp[i][j] = max(take, nottake);
            }
        }
        return dp[n - 1][n];
    }
};