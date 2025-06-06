#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int f(int i, int j, bool isTrue, string &s, vector<vector<vector<int> > > &dp)
    {
        if (i > j)
            return 0;
        if (i == j)
        {
            if (isTrue == 1)
                return s[i] == 'T' ? 1 : 0;
            else
                return s[i] == 'F' ? 1 : 0;
        }

        if (dp[i][j][isTrue] != -1)
            return dp[i][j][isTrue];

        int count = 0;
        for (int k = i + 1; k < j; k += 2)
        {
            int lT = f(i, k - 1, 1, s, dp);
            int lF = f(i, k - 1, 0, s, dp);
            int rT = f(k + 1, j, 1, s, dp);
            int rF = f(k + 1, j, 0, s, dp);

            if (s[k] == '&')
            {
                if (isTrue)
                    count = count + (lT * rT);
                else
                    count = count + (lF * rT) + (lT * rF) + (lF * rF);
            }

            else if (s[k] == '|')
            {
                if (isTrue)
                    count = count + (lF * rT) + (lT * rF) + (lT * rT);
                else
                    count = count + (lF * rF);
            }
            else
            {
                if (isTrue)
                    count = count + (lF * rT) + (lT * rF);
                else
                    count = count + (lF * rF) + (lT * rT);
            }
        }
        return dp[i][j][isTrue] = count;
    }

    int countWays(string &s)
    {
        int n = s.size();

        vector<vector<vector<int> > > dp(n, vector<vector<int> >(n, vector<int>(2, -1)));
        return f(0, n - 1, 1, s, dp);
    }
};