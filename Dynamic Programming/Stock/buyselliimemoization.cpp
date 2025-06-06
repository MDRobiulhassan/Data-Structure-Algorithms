#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int stockSum(int i, vector<int> &prices, bool buy,
                 vector<vector<int> > &dp)
    {
        int profit = 0;
        if (i == prices.size())
            return 0;

        if (dp[i][buy] != -1)
            return dp[i][buy];

        if (buy)
            profit = max(-prices[i] + stockSum(i + 1, prices, 0, dp),
                         stockSum(i + 1, prices, 1, dp));
        else
            profit = max(prices[i] + stockSum(i + 1, prices, 1, dp),
                         stockSum(i + 1, prices, 0, dp));

        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int> > dp(n, vector<int>(2, -1));
        return stockSum(0, prices, 1, dp);
    }
};