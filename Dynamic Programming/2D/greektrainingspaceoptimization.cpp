//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int maximumPoints(vector<vector<int> > &arr)
    {
        int n = arr.size();
        vector<int> dp(n, 0);

        dp[0] = max(arr[0][1], arr[0][2]);
        dp[1] = max(arr[0][0], arr[0][2]);
        dp[2] = max(arr[0][0], arr[0][1]);
        dp[3] = max(arr[0][0], max(arr[0][0], arr[0][1]));

        for (int d = 1; d < n; d++)
        {
            vector<int> temp(4, 0);
            for (int l = 0; l < 4; l++)
            {
                temp[l] = 0;

                for (int t = 0; t < 3; t++)
                {
                    if (t != l)
                    {
                        temp[l] = max(temp[l], arr[d][t] + dp[t]);
                    }
                }
            }
            dp = temp;
        }
        return dp[3];
    }
};