#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        sort(piles.begin(), piles.end());
        int mx = piles[piles.size() - 1];

        int l = 1, r = mx;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            long long sum = 0;
            for (int j = 0; j < piles.size(); j++)
            {
                int avg = ceil(double(piles[j]) / mid);
                sum += avg;
            }
            if (sum <= h)
                r = mid - 1;
            else
                l = mid + 1;
        }

        return l;
    }
};