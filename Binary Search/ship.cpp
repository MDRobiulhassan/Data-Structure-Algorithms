#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool possible(vector<int> &weights, int mid, int days)
    {
        long long load = 0;
        int count = 1;
        for (int j = 0; j < weights.size(); j++)
        {
            if (load + weights[j] > mid)
            {
                count++;
                load = 0;
            }
            load += weights[j];
        }
        if (count <= days)
            return true;
        return false;
    }

    int shipWithinDays(vector<int> &weights, int days)
    {
        int mx = *max_element(weights.begin(), weights.end());
        int sum = accumulate(weights.begin(), weights.end(), 0);

        int l = mx, r = sum;
        while (l <= r)
        {
            int mid = (l + r) / 2;

            if (possible(weights, mid, days))
                r = mid - 1;
            else
                l = mid + 1;
        }

        return l;
    }
};
