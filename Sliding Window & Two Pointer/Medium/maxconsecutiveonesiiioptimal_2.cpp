#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size();
        int l = 0, r = 0;
        int maxlen = 0;

        int z = 0;
        while (r < n)
        {
            if (nums[r] == 0)
                z++;

            if (z > k)
            {
                if (nums[l] == 0)
                    z--;
                l++;
            }

            if (z <= k)
            {
                int len = r - l + 1;
                maxlen = max(len, maxlen);
            }

            r++;
        }
        return maxlen;
    }
};