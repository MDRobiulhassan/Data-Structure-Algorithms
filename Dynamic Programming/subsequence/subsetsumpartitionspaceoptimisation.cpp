#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        if (sum % 2 != 0)
            return false;
        sum = sum / 2;
        vector<int> prev(sum + 1, false);
        prev[0] = true;
        if (nums[0] <= sum)
            prev[nums[0]] = true;

        for (int i = 1; i < nums.size(); i++)
        {
            vector<int> cur(sum + 1, false);
            cur[0] = true;
            for (int j = 1; j <= sum; j++)
            {
                bool take = false;
                if (nums[i] <= j)
                    take = prev[j - nums[i]];
                bool nottake = prev[j];

                cur[j] = take || nottake;
            }
            prev = cur;
        }

        return prev[sum];
    }
};