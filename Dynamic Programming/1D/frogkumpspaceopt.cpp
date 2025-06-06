//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int minCost(vector<int> &height)
    {
        int n = height.size();
        vector<int> dp(n, 0);

        int prev2 = 0, prev = 0;

        for (int i = 1; i < height.size(); i++)
        {
            int l = prev + abs(height[i] - height[i - 1]);
            int r = INT_MAX;
            if (i > 1)
                r = prev2 + abs(height[i] - height[i - 2]);
            int cur = min(l, r);

            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
};