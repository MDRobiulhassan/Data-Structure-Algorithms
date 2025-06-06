#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int subsetSum(int i, vector<int> &coins, int amount,
                  vector<vector<int> > &dp)
    {
        if (i == 0)
        {
            if (amount % coins[0] == 0)
                return amount / coins[0];
            return 1e9;
        }

        if (dp[i][amount] != -1)
            return dp[i][amount];

        int nottake = subsetSum(i - 1, coins, amount, dp);
        int take = 1e9;
        if (coins[i] <= amount)
        {
            int flag = subsetSum(i, coins, amount - coins[i], dp);
            if (flag != 1e9)
                take = 1 + flag;
        }

        return dp[i][amount] = min(take, nottake);
    }

    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int> > dp(n, vector<int>(amount + 1, -1));
        int ans = subsetSum(n - 1, coins, amount, dp);
        return (ans == 1e9) ? -1 : ans;
    }
};
