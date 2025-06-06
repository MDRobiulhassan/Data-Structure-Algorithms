//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution
{
public:
    int subsetSum(int i, int l, vector<int> &price, vector<vector<int> > &dp)
    {
        if (i == 0)
            return price[0] * l;
        if (dp[i][l] != -1)
            return dp[i][l];

        int nottake = subsetSum(i - 1, l, price, dp);

        int take = 0;
        if (i + 1 <= l)
            take = price[i] + subsetSum(i, l - (i + 1), price, dp);

        return dp[i][l] = max(take, nottake);
    }

    int cutRod(vector<int> &price)
    {
        int n = price.size();
        vector<vector<int> > dp(n, vector<int>(n + 1, -1));
        return subsetSum(n - 1, n, price, dp);
    }
};