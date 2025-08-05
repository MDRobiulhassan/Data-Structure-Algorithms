#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size() - 1;

        int l = 0, r = 0, jump = 0;

        while (r < n)
        {
            int furthest = 0;

            for (int i = l; i <= r; i++)
                furthest = max(nums[i] + i, furthest);

            l++;
            r = furthest;
            jump++;
        }

        return jump;
    }
};