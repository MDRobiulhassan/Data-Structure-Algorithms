//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution
{
public:
    int subsetSum(int i, vector<int> &val, vector<int> &wt, int capacity, vector<vector<int> > &dp)
    {
        if (i == 0)
        {
            if (wt[0] <= capacity)
                return val[0] * (capacity / wt[0]);
            return 0;
        }

        if (dp[i][capacity] != -1)
            return dp[i][capacity];

        int nottake = subsetSum(i - 1, val, wt, capacity, dp);
        int take = 0;
        if (wt[i] <= capacity)
            take = val[i] + subsetSum(i, val, wt, capacity - wt[i], dp);

        return dp[i][capacity] = max(take, nottake);
    }

    int knapSack(vector<int> &val, vector<int> &wt, int capacity)
    {
        int n = val.size();
        vector<vector<int> > dp(n, vector<int>(capacity + 1, -1));
        return subsetSum(n - 1, val, wt, capacity, dp);
    }
};