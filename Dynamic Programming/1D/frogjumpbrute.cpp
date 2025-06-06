#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int pathCost(int i, vector<int> &height)
    {
        if (i == 0)
            return 0;
        int l = pathCost(i - 1, height) + abs(height[i] - height[i - 1]);
        int r = INT_MAX;
        if (i > 1)
            r = pathCost(i - 2, height) + abs(height[i] - height[i - 2]);
        return min(l, r);
    }
    int minCost(vector<int> &height)
    {
        int n = height.size();

        return pathCost(n - 1, height);
    }
};