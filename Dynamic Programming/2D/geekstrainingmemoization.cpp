//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int solve(int i, vector<vector<int> > &arr, int last, vector<vector<int> > &dp)
    {
        if (i == 0)
        {
            int mx = 0;
            for (int j = 0; j < 3; j++)
            {
                if (j != last)
                    mx = max(mx, arr[0][j]);
            }
            return mx;
        }

        if (dp[i][last] != -1)
            return dp[i][last];

        int mx = 0;
        for (int j = 0; j < 3; j++)
        {
            if (j != last)
            {
                int point = arr[i][j] + solve(i - 1, arr, j, dp);
                mx = max(mx, point);
            }
        }
        return dp[i][last] = mx;
    }

    int maximumPoints(vector<vector<int> > &arr)
    {
        int n = arr.size();
        vector<vector<int> > dp(n, vector<int>(4, -1));
        return solve(n - 1, arr, 3, dp);
    }
};
