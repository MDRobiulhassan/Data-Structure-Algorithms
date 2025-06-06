#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countWays(string &s)
    {
        int n = s.size();
        vector<vector<vector<int> > > dp(n, vector<vector<int> >(n, vector<int>(2, 0)));

        for (int i = 0; i < n; i += 2)
        {
            dp[i][i][1] = (s[i] == 'T') ? 1 : 0;
            dp[i][i][0] = (s[i] == 'F') ? 1 : 0;
        }

        for (int len = 3; len <= n; len += 2)
        {
            for (int i = 0; i <= n - len; i += 2)
            {
                int j = i + len - 1;

                for (int k = i + 1; k < j; k += 2)
                {
                    char op = s[k];

                    int lT = dp[i][k - 1][1];
                    int lF = dp[i][k - 1][0];
                    int rT = dp[k + 1][j][1];
                    int rF = dp[k + 1][j][0];

                    if (op == '&')
                    {
                        dp[i][j][1] += lT * rT;
                        dp[i][j][0] += lF * rT + lT * rF + lF * rF;
                    }
                    else if (op == '|')
                    {
                        dp[i][j][1] += lF * rT + lT * rF + lT * rT;
                        dp[i][j][0] += lF * rF;
                    }
                    else if (op == '^')
                    {
                        dp[i][j][1] += lF * rT + lT * rF;
                        dp[i][j][0] += lF * rF + lT * rT;
                    }
                }
            }
        }

        return dp[0][n - 1][1];
    }
};
