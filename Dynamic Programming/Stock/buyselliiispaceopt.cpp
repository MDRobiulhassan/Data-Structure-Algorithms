#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int> > prev(2, vector<int>(3, 0));
        vector<vector<int> > cur(2, vector<int>(3, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j <= 1; j++)
            {
                int profit = 0;
                for (int k = 1; k <= 2; k++)
                {
                    if (j)
                        profit = max(-prices[i] + prev[0][k], prev[1][k]);
                    else
                        profit = max(prices[i] + prev[1][k - 1], prev[0][k]);

                    cur[j][k] = profit;
                }
                prev = cur;
            }
        }

        return prev[1][2];
    }
};