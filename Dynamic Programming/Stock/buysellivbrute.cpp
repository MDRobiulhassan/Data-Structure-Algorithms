#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int stockSum(int i, int buy, vector<int> &prices, int k)
    {
        int profit = 0;
        if (k == 0)
            return 0;
        if (i == prices.size())
            return 0;

        if (buy)
            profit = max(-prices[i] + stockSum(i + 1, 0, prices, k),
                         stockSum(i + 1, 1, prices, k));
        else
            profit = max(prices[i] + stockSum(i + 1, 1, prices, k - 1),
                         stockSum(i + 1, 0, prices, k));

        return profit;
    }

    int maxProfit(int k, vector<int> &prices)
    {
        return stockSum(0, 1, prices, k);
    }
};