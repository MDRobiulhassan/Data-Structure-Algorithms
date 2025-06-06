#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int stockSum(int i, vector<int> &prices, bool buy, int cap)
    {
        int profit = 0;
        if (cap == 0)
            return 0;
        if (i == prices.size())
            return 0;

        if (buy)
            profit = max(-prices[i] + stockSum(i + 1, prices, 0, cap),
                         stockSum(i + 1, prices, 1, cap));
        else
            profit = max(prices[i] + stockSum(i + 1, prices, 1, cap - 1),
                         stockSum(i + 1, prices, 0, cap));

        return profit;
    }

    int maxProfit(vector<int> &prices) { return stockSum(0, prices, 1, 2); }
};