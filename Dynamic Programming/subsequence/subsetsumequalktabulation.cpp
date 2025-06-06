//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function template for C++

class Solution
{
public:
    bool isSubsetSum(vector<int> &arr, int target)
    {
        vector<vector<bool> > dp(arr.size(), vector<bool>(target + 1, false));
        for (int i = 0; i < arr.size(); i++)
            dp[i][0] = true;
        if (arr[0] <= target)
            dp[0][arr[0]] = true;

        for (int i = 1; i < arr.size(); i++)
        {
            for (int j = 1; j <= target; j++)
            {
                bool nottake = dp[i - 1][j];
                bool take = false;
                if (arr[i] <= j)
                    take = dp[i - 1][j - arr[i]];

                dp[i][j] = take || nottake;
            }
        }

        return dp[arr.size() - 1][target];
    }
};