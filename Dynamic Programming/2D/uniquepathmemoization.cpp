#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countPath(int i, int j, vector<vector<int> > &dp)
    {
        if (i == 0 && j == 0)
            return 1;

        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int u = 0, l = 0;
        l += countPath(i - 1, j, dp);
        u += countPath(i, j - 1, dp);
        return dp[i][j] = l + u;
    }

    int uniquePaths(int m, int n)
    {
        vector<vector<int> > dp(m, vector<int>(n, -1));
        return countPath(m - 1, n - 1, dp);
    }
};