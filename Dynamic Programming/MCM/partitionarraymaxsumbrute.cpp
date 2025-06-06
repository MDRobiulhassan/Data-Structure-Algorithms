#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int f(int i, vector<int> &a, int k)
    {
        int n = a.size();
        if (i == a.size())
            return 0;

        int ans = INT_MIN;
        int mx = INT_MIN;
        int len = 0;
        for (int j = i; j < (min(n, i + k)); j++)
        {
            len++;
            mx = max(mx, a[j]);
            int sum = (len * mx) + f(j + 1, a, k);
            ans = max(ans, sum);
        }
        return ans;
    }

    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        return f(0, arr, k);
    }
};