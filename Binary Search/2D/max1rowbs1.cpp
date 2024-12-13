//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int rowWithMax1s(vector<vector<int> > &arr)
    {
        int n = arr.size();
        int m = arr[0].size();
        int maxcount = 0;
        int ind = -1;

        for (int i = 0; i < n; i++)
        {
            int l = 0, r = m - 1;
            while (l <= r)
            {
                int mid = (l + r) / 2;

                if (arr[i][mid] == 1)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            int count = m - l;
            if (count > maxcount)
            {
                maxcount = count;
                ind = i;
            }
        }
        return ind;
    }
};


