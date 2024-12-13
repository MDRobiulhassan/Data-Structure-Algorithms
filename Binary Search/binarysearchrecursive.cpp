#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int binarysearch(vector<int> &nums, int target, int l, int r)
    {
        int mid = (l + r) / 2;
        if (l > r)
            return -1;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            return binarysearch(nums, target, l, mid - 1);
        else
            return binarysearch(nums, target, mid + 1, r);
    }
    int search(vector<int> &nums, int target)
    {
        return binarysearch(nums, target, 0, nums.size() - 1);
    }
};