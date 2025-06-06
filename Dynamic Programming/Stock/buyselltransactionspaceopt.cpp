#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<int> prev(2, 0);
        vector<int> cur(2, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            int profit = 0;
            for (int buy = 0; buy < 2; buy++)
            {
                if (buy)
                    profit = max(-prices[i] + prev[0], prev[1]);
                else
                    profit = max(prices[i] + prev[1] - fee, prev[0]);

                cur[buy] = profit;
            }
            prev = cur;
        }

        return prev[1];
    }
};