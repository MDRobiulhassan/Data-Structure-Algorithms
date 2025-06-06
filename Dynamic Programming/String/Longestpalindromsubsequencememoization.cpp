#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int LCS(int i, int j, string &s, string &s1, vector<vector<int> > &dp)
    {
        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == s1[j])
            return dp[i][j] = 1 + LCS(i - 1, j - 1, s, s1, dp);

        return dp[i][j] = max(LCS(i - 1, j, s, s1, dp), LCS(i, j - 1, s, s1, dp));
    }

    int longestPalindromeSubseq(string s)
    {
        string s1 = s;
        reverse(s1.begin(), s1.end());
        int n = s.size();
        vector<vector<int> > dp(n, vector<int>(n, -1));
        return LCS(n - 1, n - 1, s, s1, dp);
    }
};