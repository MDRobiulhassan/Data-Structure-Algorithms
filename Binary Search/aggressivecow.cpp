#include <bits/stdc++.h>
using namespace std;

bool canplace(vector<int> &stalls, int mid, int k)
{
    int lastcow = stalls[0];
    int count = 1;

    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - lastcow >= mid)
        {
            count++;
            lastcow = stalls[i];
        }
        if (count >= k)
            return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    int limit = stalls[n - 1] - stalls[0];

    int l = 1, r = limit;
    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (canplace(stalls, mid, k))
            l = mid + 1;
        else
            r = mid - 1;
    }
    return r;
}