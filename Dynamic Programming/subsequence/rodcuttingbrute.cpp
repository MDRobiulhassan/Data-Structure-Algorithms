#include <bits/stdc++.h>
using namespace std;
// User function Template for C++

class Solution
{
public:
    int subsetSum(int i, int l, vector<int> &price)
    {
        if (i == 0)
            return price[0] * l;

        int nottake = subsetSum(i - 1, l, price);

        int take = 0;
        if (i + 1 <= l)
            take = price[i] + subsetSum(i, l - (i + 1), price);

        return max(take, nottake);
    }

    int cutRod(vector<int> &price)
    {
        int n = price.size();
        return subsetSum(n - 1, n, price);
    }
};