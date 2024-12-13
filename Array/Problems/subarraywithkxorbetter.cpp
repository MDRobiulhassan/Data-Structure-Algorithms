#include <bits/stdc++.h>
using namespace std;

int subarraysWithSumK(vector<int> a, int b)
{
    int count = 0;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        // xr=a[i];
        int xr = 0;
        for (int j = i; j < n; j++)
        {
            xr = xr ^ a[j];
            if (xr == b)
                count++;
        }
    }
    return count;
}