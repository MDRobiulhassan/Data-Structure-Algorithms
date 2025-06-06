#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prev(n + 1, 0);
        vector<int> cur(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            for (int prev_i = i - 1; prev_i >= -1; prev_i--)
            {
                int len = prev[prev_i + 1];

                if (prev_i == -1 || nums[i] > nums[prev_i])
                    len = max(len, 1 + prev[i + 1]);

                cur[prev_i + 1] = len;
            }
            prev = cur;
        }
        return prev[0];
    }
};