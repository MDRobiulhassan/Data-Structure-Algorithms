#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int matrixMultiplication(vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<int> > dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 1; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                int mn = 1e9;
                for (int k = i; k < j; k++)
                {
                    int steps = (arr[i - 1] * arr[j] * arr[k]) + dp[i][k] + dp[k + 1][j];

                    mn = min(steps, mn);
                }
                dp[i][j] = mn;
            }
        }

        return dp[1][n - 1];
    }
};