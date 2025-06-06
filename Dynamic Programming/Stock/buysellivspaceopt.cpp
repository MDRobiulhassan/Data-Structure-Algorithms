#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int> > prev(2, vector<int>(k + 1, 0));
        vector<vector<int> > cur(2, vector<int>(k + 1, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j <= 1; j++)
            {
                int profit = 0;
                for (int m = 1; m <= k; m++)
                {
                    if (j)
                        profit = max(-prices[i] + prev[0][m], prev[1][m]);
                    else
                        profit = max(prices[i] + prev[1][m - 1], prev[0][m]);

                    cur[j][m] = profit;
                }
                prev = cur;
            }
        }
        return prev[1][k];
    }
};