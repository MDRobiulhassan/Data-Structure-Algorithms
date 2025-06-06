#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Recursive helper function to calculate max profit
    // i = current day (index in prices)
    // buy = true if we are allowed to buy, false if we are allowed to sell
    int stockSum(int i, vector<int> &prices, bool buy)
    {
        // Base case: If we are past the last day, we can't make any more transactions
        if (i == prices.size())
            return 0;

        int profit = 0;

        if (buy)
        {
            // Two choices:
            // 1. Buy the stock at prices[i], then move to next day with sell permission
            // 2. Skip buying, move to next day with buy permission still active
            profit = max(-prices[i] + stockSum(i + 1, prices, 0), // Buy
                         stockSum(i + 1, prices, 1));             // Don't buy (skip)
        }
        else
        {
            // Two choices:
            // 1. Sell the stock at prices[i], then move to next day with buy permission
            // 2. Skip selling, move to next day with sell permission still active
            profit = max(prices[i] + stockSum(i + 1, prices, 1), // Sell
                         stockSum(i + 1, prices, 0));            // Don't sell (skip)
        }

        return profit;
    }

    int maxProfit(vector<int> &prices)
    {
        // Start from day 0 with permission to buy
        return stockSum(0, prices, 1);
    }
};
