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
            vector<int> cur(W + 1, 0);
            for (int j = 0; j <= W; j++)
            {
                int nottake = prev[j];

                int take = 0;

                if (wt[i] <= j)
                    take = val[i] + prev[j - wt[i]];

                cur[j] = max(take, nottake);
            }
            prev = cur;
        }
        return prev[W];
    }
};