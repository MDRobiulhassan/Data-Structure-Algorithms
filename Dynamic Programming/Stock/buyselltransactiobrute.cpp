#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int stockSum(int i, int buy, vector<int> &prices, int fee)
    {
        int profit = 0;
        if (i == prices.size())
            return 0;

        if (buy)
            profit = max(-prices[i] + stockSum(i + 1, 0, prices, fee),
                         stockSum(i + 1, 1, prices, fee));
        else
            profit = max(prices[i] + stockSum(i + 1, 1, prices, fee) - fee,
                         stockSum(i + 1, 0, prices, fee));

        return profit;
    }

    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        return stockSum(0, 1, prices, fee);
    }
};