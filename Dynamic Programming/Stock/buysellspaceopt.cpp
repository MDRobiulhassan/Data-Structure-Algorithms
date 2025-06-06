#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> prev(2, 0);
        vector<int> cur(2, 0);

        prev[0] = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            int profit = 0;
            for (int j = 0; j < 2; j++)
            {
                if (j)
                    profit = max(-prices[i] + prev[0], prev[1]);
                else
                    profit = max(prices[i] + prev[1], prev[0]);

                cur[j] = profit;
            }
            prev = cur;
        }
        return prev[1];
    }
};