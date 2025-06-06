#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int countPartitions(vector<int> &arr, int d)
    {
        int total = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++)
            total += arr[i];

        if (total - d < 0 || (total - d) % 2 != 0)
            return 0;
        int target = (total - d) / 2;
        vector<vector<int> > dp(n, vector<int>(target + 1, 0));

        dp[0][0] = (arr[0] == 0) ? 2 : 1;
        if (arr[0] != 0 && arr[0] <= target)
            dp[0][arr[0]] = 1;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= target; j++)
            {
                int nottake = dp[i - 1][j];
                int take = 0;
                if (arr[i] <= j)
                    take = dp[i - 1][j - arr[i]];

                dp[i][j] = take + nottake;
            }
        }

        return dp[n - 1][target];
    }
};
