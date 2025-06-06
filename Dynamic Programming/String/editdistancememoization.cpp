#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int editDistance(int i, int j, string s, string t,
                     vector<vector<int> > &dp)
    {
        if (i < 0)
            return j + 1;
        if (j < 0)
            return i + 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == t[j])
            return dp[i][j] = editDistance(i - 1, j - 1, s, t, dp);

        int insert = 1 + editDistance(i, j - 1, s, t, dp);
        int dlt = 1 + editDistance(i - 1, j, s, t, dp);
        int replace = 1 + editDistance(i - 1, j - 1, s, t, dp);

        return dp[i][j] = min(insert, min(dlt, replace));
    }

    int minDistance(string word1, string word2)
    {
        int n = word1.size(), m = word2.size();
        vector<vector<int> > dp(n, vector<int>(m, -1));
        return editDistance(n - 1, m - 1, word1, word2, dp);
    }
};