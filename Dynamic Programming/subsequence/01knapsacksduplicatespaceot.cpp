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
        vector<int> prev(capacity + 1, 0);

        for (int i = 0; i <= capacity; i++)
            prev[i] = val[0] * (i / wt[0]);

        for (int i = 1; i < n; i++)
        {
            vector<int> cur(capacity + 1, 0);
            for (int j = 0; j <= capacity; j++)
            {
                int nottake = prev[j];
                int take = 0;
                if (wt[i] <= j)
                    take = val[i] + cur[j - wt[i]];

                cur[j] = max(take, nottake);
            }
            prev = cur;
        }
        return prev[capacity];
    }
};