#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool possible(int m, int k, vector<int> &bloomDay, int mid)
    {
        int count = 0, b = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] <= mid)
            {
                count++;
                if (count == k)
                {
                    count = 0;
                    b++;
                }
            }
            else
                count = 0;

            if (b >= m)
                return true;
        }
        return false;
    }
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int n = bloomDay.size();

        long long mult = (long long)(m)*k;
        if (mult > n)
            return -1;
        int mx = *max_element(bloomDay.begin(), bloomDay.end());
        int l = 1, r = mx;
        while (l <= r)
        {
            int mid = (l + r) / 2;

            if (possible(m, k, bloomDay, mid))
                r = mid - 1;
            else
                l = mid + 1;
        }

        return l;
    }
};