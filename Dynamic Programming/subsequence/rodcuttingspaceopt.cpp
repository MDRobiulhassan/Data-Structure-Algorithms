//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution
{
public:
    int cutRod(vector<int> &price)
    {
        int n = price.size();
        vector<int> prev(n + 1, 0);
        vector<int> cur(n + 1, 0);
        for (int i = 0; i <= n; i++)
            prev[i] = price[0] * i;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                int nottake = prev[j];

                int take = 0;
                if (i + 1 <= j)
                    take = price[i] + cur[j - (i + 1)];

                cur[j] = max(take, nottake);
            }
            prev = cur;
        }
        return prev[n];
    }
};