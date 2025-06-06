//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int knapSack(int i, int W, vector<int> &val, vector<int> &wt)
    {
        if (i == 0)
            return (wt[0] <= W) ? val[0] : 0;

        int nottake = knapSack(i - 1, W, val, wt);

        int take = 0;

        if (wt[i] <= W)
            take = val[i] + knapSack(i - 1, W - wt[i], val, wt);

        return max(take, nottake);
    }

    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        return knapSack(val.size() - 1, W, val, wt);
    }
};