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
        vector<bool> prev(target + 1, false);
        prev[0] = true;
        if (arr[0] <= target)
            prev[arr[0]] = true;

        for (int i = 1; i < arr.size(); i++)
        {
            vector<bool> cur(target + 1, false);
            cur[0] = true;
            for (int j = 1; j <= target; j++)
            {
                bool nottake = prev[j];
                bool take = false;
                if (arr[i] <= j)
                    take = prev[j - arr[i]];

                cur[j] = take || nottake;
            }
            prev = cur;
        }

        return prev[target];
    }
};