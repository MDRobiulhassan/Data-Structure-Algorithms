#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int res = 0;
        int n = height.size();
        int l = 0, r = n - 1;
        int maxLeft = 0, maxRight = 0;

        while (l <= r)
        {
            if (height[l] <= height[r])
            {
                if (height[l] >= maxLeft)
                    maxLeft = height[l];
                else
                    res += maxLeft - height[l];

                l++;
            }
            else
            {
                if (height[r] >= maxRight)
                    maxRight = height[r];
                else
                    res += maxRight - height[r];
                r--;
            }
        }
        return res;
    }
};