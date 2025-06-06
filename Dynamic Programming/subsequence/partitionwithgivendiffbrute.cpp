//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int subsetSum(int i, vector<int> &arr, int target)
    {
        if (i < 0)
            return target == 0;

        int nottake = subsetSum(i - 1, arr, target);
        int take = 0;
        if (arr[i] <= target)
            take = subsetSum(i - 1, arr, target - arr[i]);

        return take + nottake;
    }

    int countPartitions(vector<int> &arr, int d)
    {
        int total = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++)
            total += arr[i];

        if (total - d < 0 || (total - d) % 2 != 0)
            return false;
        int target = (total - d) / 2;
        return subsetSum(n - 1, arr, target);
    }
};