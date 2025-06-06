#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int stockSum(int i, vector<int> &prices, int buy, int cap,
                 vector<vector<vector<int> > > &dp)
    {
        int profit = 0;
        if (cap == 0)
            return 0;
        if (i == prices.size())
            return 0;

        if (dp[i][buy][cap] != -1)
            return dp[i][buy][cap];

        if (buy)
            profit = max(-prices[i] + stockSum(i + 1, prices, 0, cap, dp),
                         stockSum(i + 1, prices, 1, cap, dp));
        else
            profit = max(prices[i] + stockSum(i + 1, prices, 1, cap - 1, dp),
                         stockSum(i + 1, prices, 0, cap, dp));

        return dp[i][buy][cap] = profit;
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int> > > dp(
            n, vector<vector<int> >(2, vector<int>(3, -1)));
        return stockSum(0, prices, 1, 2, dp);
    }
};