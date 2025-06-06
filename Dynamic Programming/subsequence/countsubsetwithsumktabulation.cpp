#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int perfectSum(vector<int> &arr, int target)
    {
        vector<vector<int> > dp(arr.size(), vector<int>(target + 1, 0));

        for (int i = 0; i < arr.size(); i++)
            dp[i][0] = 1;
        if (arr[0] <= target)
            dp[0][arr[0]] += 1;

        for (int i = 1; i < arr.size(); i++)
        {
            for (int j = 0; j <= target; j++)
            {
                int take = 0;
                if (j >= arr[i])
                    take = dp[i - 1][j - arr[i]];
                int nottake = dp[i - 1][j];

                dp[i][j] = take + nottake;
            }
        }
        return dp[arr.size() - 1][target];
    }
};