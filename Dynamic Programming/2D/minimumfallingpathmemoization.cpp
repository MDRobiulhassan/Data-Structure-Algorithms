#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int pathSum(int i, int j, vector<vector<int> > &matrix,
                vector<vector<int> > &dp)
    {
        if (j < 0 || j >= matrix[0].size())
            return 1e9;

        if (i == 0)
            return matrix[0][j];

        if (dp[i][j] != -1)
            return dp[i][j];
        int t = matrix[i][j] + pathSum(i - 1, j, matrix, dp);
        int ld = matrix[i][j] + pathSum(i - 1, j - 1, matrix, dp);
        int rd = matrix[i][j] + pathSum(i - 1, j + 1, matrix, dp);

        return dp[i][j] = min(min(t, ld), rd);
    }

    int minFallingPathSum(vector<vector<int> > &matrix)
    {
        int n = matrix.size();
        vector<vector<int> > dp(n, vector<int>(n, -1));

        int ans = 1e9;
        for (int i = 0; i < n; i++)
        {
            ans = min(ans, pathSum(n - 1, i, matrix, dp));
        }
        return ans;
    }
};