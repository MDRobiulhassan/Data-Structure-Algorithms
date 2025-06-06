#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<double> > dp(n, vector<double>(amount + 1, 0));

        for (int j = 0; j <= amount; j++)
            dp[0][j] = (j % coins[0] == 0);

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                double nottake = dp[i - 1][j];
                double take = 0;
                if (coins[i] <= j)
                    take = dp[i][j - coins[i]];
                dp[i][j] = take + nottake;
            }
        }
        return (int)dp[n - 1][amount];
    }
};
