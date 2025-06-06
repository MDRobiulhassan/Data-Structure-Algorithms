#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int f(int i, vector<int> &a, int k, vector<int> &dp)
    {
        int n = a.size();
        if (i == a.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int ans = INT_MIN;
        int mx = INT_MIN;
        int len = 0;
        for (int j = i; j < (min(n, i + k)); j++)
        {
            len++;
            mx = max(mx, a[j]);
            int sum = (len * mx) + f(j + 1, a, k, dp);
            ans = max(ans, sum);
        }
        return dp[i] = ans;
    }

    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n, -1);
        return f(0, arr, k, dp);
    }
};