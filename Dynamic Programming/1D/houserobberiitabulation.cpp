#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int subsetsum(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 0)
            return 0;

        vector<int> dp1(n, 0);
        dp1[0] = nums[0];
        if (n > 1)
            dp1[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n - 1; i++)
        {
            int pick = nums[i] + dp1[i - 2];
            int notpick = dp1[i - 1];
            dp1[i] = max(pick, notpick);
        }

        vector<int> dp2(n, 0);
        dp2[0] = 0;

        for (int i = 1; i < n; i++)
        {
            int pick = nums[i] + (i >= 2 ? dp2[i - 2] : 0);
            int notpick = dp2[i - 1];
            dp2[i] = max(pick, notpick);
        }
        return max(dp1[n - 2], dp2[n - 1]);
    }

    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        return subsetsum(nums);
    }
};
