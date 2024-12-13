#include <bits/stdc++.h>
using namespace std;
int subarraysWithSumK(vector<int> a, int b)
{
    int count = 0;
    int n = a.size();
    int xr = 0;
    unordered_map<int, int> pf;
    pf[0]++;
    for (int i = 0; i < n; i++)
    {
        xr = xr ^ a[i];
        int x = xr ^ b;
        count += pf[x];
        pf[xr]++;
    }
    return count;
}