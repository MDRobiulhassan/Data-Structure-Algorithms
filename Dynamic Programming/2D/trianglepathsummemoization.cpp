#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int pathSum(int i, int j, vector<vector<int> > &triangle,
                vector<vector<int> > &dp)
    {
        int n = triangle.size();
        int m = triangle[i].size();
        if (i == n - 1)
            return triangle[i][j];
        if (dp[i][j] != -1)
            return dp[i][j];

        int t, l;
        t = triangle[i][j] + pathSum(i + 1, j, triangle, dp);
        l = triangle[i][j] + pathSum(i + 1, j + 1, triangle, dp);
        return dp[i][j] = min(t, l);
    }

    int minimumTotal(vector<vector<int> > &triangle)
    {
        int n = triangle.size();
        vector<vector<int> > dp(n, vector<int>(n, -1));
        return pathSum(0, 0, triangle, dp);
    }
};