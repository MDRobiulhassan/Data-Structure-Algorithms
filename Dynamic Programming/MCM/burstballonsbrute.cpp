#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int burstCost(int i, int j, vector<int> &nums)
    {
        if (i > j)
            return 0;

        int mx = 0;
        for (int k = i; k <= j; k++)
        {
            int cost = (i - 1 < 0 ? 1 : nums[i - 1]) * nums[k] *
                           (j + 1 >= nums.size() ? 1 : nums[j + 1]) +
                       burstCost(i, k - 1, nums) + burstCost(k + 1, j, nums);

            mx = max(mx, cost);
        }

        return mx;
    }

    int maxCoins(vector<int> &nums)
    {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        return burstCost(1, n - 2, nums);
    }
};