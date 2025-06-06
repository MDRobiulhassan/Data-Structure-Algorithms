#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &a)
    {
        int mn = a[0], profit = 0;
        int n = a.size();
        for (int i = 1; i < n; i++)
        {
            int cost = a[i] - mn;

            profit = max(profit, cost);
            mn = min(a[i], mn);
        }

        return profit;
    }
};