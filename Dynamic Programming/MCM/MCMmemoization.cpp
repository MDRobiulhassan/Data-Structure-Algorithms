#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int MCM(int i, int j, vector<int> &arr, vector<vector<int> > &dp)
    {
        if (i == j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int mn = 1e9;
        for (int k = i; k < j; k++)
        {
            int steps = (arr[i - 1] * arr[j] * arr[k]) + MCM(i, k, arr, dp) + MCM(k + 1, j, arr, dp);

            mn = min(steps, mn);
        }
        return dp[i][j] = mn;
    }

    int matrixMultiplication(vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<int> > dp(n, vector<int>(n, -1));
        return MCM(1, n - 1, arr, dp);
    }
};