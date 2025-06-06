#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxSumAfterPartitioning(vector<int> &a, int k)
    {
        int n = a.size();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            int ans = INT_MIN;
            int mx = INT_MIN;
            int len = 0;
            for (int j = i; j < (min(n, i + k)); j++)
            {
                len++;
                mx = max(mx, a[j]);
                int sum = (len * mx) + dp[j + 1];
                ans = max(ans, sum);
            }
            dp[i] = ans;
        }
        return dp[0];
    }
};