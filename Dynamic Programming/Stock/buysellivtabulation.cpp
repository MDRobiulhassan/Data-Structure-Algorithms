#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int stockSum(int i, int buy, vector<int> &prices, int k,
                 vector<vector<vector<int> > > &dp)
    {
        int profit = 0;
        if (k == 0)
            return 0;
        if (i == prices.size())
            return 0;
        if (dp[i][buy][k] != -1)
            return dp[i][buy][k];

        if (buy)
            profit = max(-prices[i] + stockSum(i + 1, 0, prices, k, dp),
                         stockSum(i + 1, 1, prices, k, dp));
        else
            profit = max(prices[i] + stockSum(i + 1, 1, prices, k - 1, dp),
                         stockSum(i + 1, 0, prices, k, dp));

        return dp[i][buy][k] = profit;
    }

    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int> > > dp(
            n + 1, vector<vector<int> >(2, vector<int>(k + 1, 0)));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j <= 1; j++)
            {
                int profit = 0;
                for (int m = 1; m <= k; m++)
                {
                    if (j)
                        profit =
                            max(-prices[i] + dp[i + 1][0][m],
                                dp[i + 1][1][m]);
                    else
                        profit =
                            max(prices[i] + dp[i + 1][1][m - 1], dp[i + 1][0][m]);

                    dp[i][j][m] = profit;
                }
            }
        }
        return dp[0][1][k];
    }
};