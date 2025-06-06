#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int LPS(int i, int j, string &s, string &s2, vector<vector<int> > &dp)
    {
        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == s2[j])
            return dp[i][j] = 1 + LPS(i - 1, j - 1, s, s2, dp);

        return dp[i][j] =
                   max(LPS(i - 1, j, s, s2, dp), LPS(i, j - 1, s, s2, dp));
    }

    int minInsertions(string s)
    {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        int n = s.size();
        vector<vector<int> > dp(n, vector<int>(n, -1));

        int lpslen = LPS(n - 1, n - 1, s, s2, dp);
        return n - lpslen;
    }
};