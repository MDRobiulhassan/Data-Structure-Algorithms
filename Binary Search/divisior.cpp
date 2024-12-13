#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool possible(vector<int> &nums, int threshold, int mid)
    {
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += ceil(double(nums[i]) / mid);
        }
        if (sum <= threshold)
            return true;
        return false;
    }

    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int l = 1, r = nums[n - 1];
        while (l <= r)
        {
            int mid = (l + r) / 2;

            if (possible(nums, threshold, mid))
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
};