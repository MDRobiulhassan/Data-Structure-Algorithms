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
        vector<int> prev(W + 1, 0);
        for (int i = wt[0]; i <= W; i++)
            prev[i] = val[0];

        for (int i = 1; i < n; i++)
        {
            for (int j = W; j >= 0; j--)
            {
                int nottake = prev[j];

                int take = 0;

                if (wt[i] <= j)
                    take = val[i] + prev[j - wt[i]];

                prev[j] = max(take, nottake);
            }
        }
        return prev[W];
    }
};