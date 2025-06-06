#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int stockSum(int i, int buy, vector<int> &prices)
    {
        int profit = 0;
        if (i >= prices.size())
            return 0;

        if (buy)
            profit = max(-prices[i] + stockSum(i + 1, 0, prices),
                         stockSum(i + 1, 1, prices));
        else
            profit = max(prices[i] + stockSum(i + 2, 1, prices),
                         stockSum(i + 1, 0, prices));

        return profit;
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        return stockSum(0, 1, prices);
    }
};