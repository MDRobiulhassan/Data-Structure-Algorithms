#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    const int mod = 1e9 + 7;
    long long int memoization(int n, vector<long long int> &dp)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = (memoization(n - 1, dp) + memoization(n - 2, dp)) % mod;
    }

    long long int tabulation(int n, vector<long long int> &dp)
    {
        dp[0] = 0, dp[1] = 1;
        for (int i = 2; i <= n; i++)
            dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
        return dp[n];
    }
    long long int topDown(int n)
    {
        vector<long long int> dp(n + 1, -1);
        return memoization(n, dp);
    }
    long long int bottomUp(int n)
    {
        vector<long long int> dp(n + 1, -1);
        return tabulation(n, dp);
    }
};