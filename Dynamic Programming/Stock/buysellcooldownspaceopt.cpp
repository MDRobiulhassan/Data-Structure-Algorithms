#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> ahead1(2, 0); // dp[i+1]
        vector<int> ahead2(2, 0); // dp[i+2]
        vector<int> cur(2, 0);    // dp[i]

        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy < 2; buy++)
            {
                if (buy)
                    cur[buy] = max(-prices[i] + ahead1[0], ahead1[1]);
                else
                    cur[buy] = max(prices[i] + ahead2[1], ahead1[0]);
            }
            ahead2 = ahead1;
            ahead1 = cur;
        }

        return cur[1];
    }
};
