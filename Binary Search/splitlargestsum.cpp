#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool countarray(vector<int> &nums, int mid, int k)
    {
        long long sum = 0;
        int count = 1;

        for (int j = 0; j < nums.size(); j++)
        {
            if (sum + nums[j] <= mid)
                sum += nums[j];
            else
            {
                count++;
                sum = nums[j];
            }
        }
        return count <= k;
    }

    int splitArray(vector<int> &nums, int k)
    {
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);

        while (l <= r)
        {
            int mid = (l + r) / 2;

            if (countarray(nums, mid, k))
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
};