#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        int st = -1, end = -1;

        // lower bound
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] == target)
            {
                st = mid;
                r = mid - 1;
            }
            else if (nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }

        // upper bound
        l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] == target)
            {
                end = mid;
                l = mid + 1;
            }
            else if (nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }

        return {st, end};
    }
};