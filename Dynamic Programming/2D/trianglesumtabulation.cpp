#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumTotal(vector<vector<int> > &triangle)
    {
        int n = triangle.size();
        vector<vector<int> > dp(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = triangle[i].size() - 1; j >= 0; j--)
            {
                if (i == n - 1)
                    dp[i][j] = triangle[i][j];
                else
                {
                    int t, l;
                    t = triangle[i][j] + dp[i + 1][j];
                    l = triangle[i][j] + dp[i + 1][j + 1];
                    dp[i][j] = min(t, l);
                }
            }
        }
        return dp[0][0];
    }
};