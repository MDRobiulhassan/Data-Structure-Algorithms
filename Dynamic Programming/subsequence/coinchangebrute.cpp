#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int subsetSum(int i, vector<int> &coins, int amount)
    {
        if (i == 0)
        {
            if (amount % coins[0] == 0)
                return amount / coins[0];
            return 1e9;
        }

        int nottake = subsetSum(i - 1, coins, amount);
        int take = 1e9;
        if (coins[i] <= amount)
        {
            int flag = subsetSum(i, coins, amount - coins[i]);
            if (flag != 1e9)
                take = 1 + flag;
        }

        return min(take, nottake);
    }

    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        int ans = subsetSum(n - 1, coins, amount);
        return (ans == 1e9) ? -1 : ans;
    }
};
