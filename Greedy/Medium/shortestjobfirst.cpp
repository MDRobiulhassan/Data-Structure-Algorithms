#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long solve(vector<int> &bt)
    {
        int n = bt.size();

        sort(bt.begin(), bt.end());

        int wt = 0;
        int et = 0;
        for (int i = 0; i < n - 1; i++)
        {
            et += bt[i];
            wt += et;
        }

        return (wt / n);
    }
};