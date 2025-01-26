#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int total = 0;

        int prefix[100000], suffix[100000];
        prefix[0] = height[0];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = max(prefix[i - 1], height[i]);
        }

        suffix[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            suffix[i] = max(suffix[i + 1], height[i]);
        }

        for (int i = 0; i < n; i++)
        {
            int leftmax = prefix[i], rightmax = suffix[i];
            if (height[i] < leftmax && height[i] < rightmax)
                total += (min(leftmax, rightmax) - height[i]);
        }
        return total;
    }
};