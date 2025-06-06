//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution
{
public:
    int subsetSum(int i, vector<int> &val, vector<int> &wt, int capacity)
    {
        if (i == 0)
        {
            if (wt[0] <= capacity)
                return val[0] * (capacity / wt[0]);
            return 0;
        }

        int nottake = subsetSum(i - 1, val, wt, capacity);
        int take = 0;
        if (wt[i] <= capacity)
            take = val[i] + subsetSum(i, val, wt, capacity - wt[i]);

        return max(take, nottake);
    }

    int knapSack(vector<int> &val, vector<int> &wt, int capacity)
    {
        int n = val.size();
        return subsetSum(n - 1, val, wt, capacity);
    }
};