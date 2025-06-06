//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int findPath(int i, int k, vector<int> &arr)
    {
        if (i == 0)
            return 0;
        int ans = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
                ans = min(ans, findPath(i - j, k, arr) + abs(arr[i] - arr[i - j]));
        }
        return ans;
    }

    int minimizeCost(int k, vector<int> &arr)
    {
        int n = arr.size();
        return findPath(n - 1, k, arr);
    }
};