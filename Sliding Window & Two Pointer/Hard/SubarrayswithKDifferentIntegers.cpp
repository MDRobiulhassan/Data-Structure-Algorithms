#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countsubarray(vector<int> &nums, int k)
    {
        if (k < 0)
            return 0;
        int n = nums.size();
        int l = 0, r = 0;
        map<int, int> m;
        int count = 0;

        while (r < n)
        {
            m[nums[r]]++;

            while (m.size() > k)
            {
                m[nums[l]]--;
                if (m[nums[l]] == 0)
                    m.erase(nums[l]);

                l++;
            }

            count += (r - l + 1);
            r++;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return countsubarray(nums, k) - countsubarray(nums, k - 1);
    }
};