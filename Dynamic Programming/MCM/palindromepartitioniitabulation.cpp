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

    int minCut(string s)
    {
        int n = s.size();
        vector<int> dp(n + 1, 0);

        int mincost = INT_MAX;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (isPalindrome(i, j, s))
                {
                    int cost = dp[j + 1] + 1;
                    mincost = min(cost, mincost);
                }
            }

            dp[i] = mincost;
        }
        return dp[0];
    }
};