#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countWays(int i, vector<int> &dp)
    {
        if (i == 0 || i == 1)
            return 1;
        if (dp[i] != -1)
            return dp[i];
        return dp[i] = countWays(i - 1, dp) + countWays(i - 2, dp);
    }
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        return countWays(n, dp);
    }
};