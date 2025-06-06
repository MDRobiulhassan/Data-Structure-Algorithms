#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int subsetSum(int i, vector<int> &coins, int amount)
    {
        if (i == 0)
            return amount % coins[0] == 0;

        int nottake = subsetSum(i - 1, coins, amount);
        int take = 0;
        if (coins[i] <= amount)
            take = subsetSum(i, coins, amount - coins[i]);
        return take + nottake;
    }

    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        return subsetSum(n - 1, coins, amount);
    }
};