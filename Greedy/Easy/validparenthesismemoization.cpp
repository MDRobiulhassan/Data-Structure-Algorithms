#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool check(int i, string &s, int count, vector<vector<int> > &dp)
    {
        if (count < 0)
            return false;
        if (i == s.size())
            return count == 0;

        if (dp[i][count] != -1)
            return dp[i][count];

        if (s[i] == '(')
            return check(i + 1, s, count + 1, dp);
        if (s[i] == ')')
            return check(i + 1, s, count - 1, dp);
        return dp[i][count] = check(i + 1, s, count + 1, dp) ||
                              check(i + 1, s, count, dp) ||
                              check(i + 1, s, count - 1, dp);
    }

    bool checkValidString(string s)
    {
        int n = s.size();
        vector<vector<int> > dp(n, vector<int>(n, -1));

        return check(0, s, 0, dp);
    }
};