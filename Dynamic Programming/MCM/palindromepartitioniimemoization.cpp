#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPalindrome(int i, int j, string &s)
    {
        int n = s.size();
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    int f(int i, int n, string &s, vector<int> &dp)
    {
        if (i == n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int mincost = INT_MAX;
        for (int j = i; j < n; j++)
        {
            if (isPalindrome(i, j, s))
            {
                int cost = f(j + 1, n, s, dp) + 1;
                mincost = min(cost, mincost);
            }
        }

        return dp[i] = mincost;
    }

    int minCut(string s)
    {
        int n = s.size();
        vector<int> dp(n, -1);
        return f(0, n, s, dp) - 1;
    }
};