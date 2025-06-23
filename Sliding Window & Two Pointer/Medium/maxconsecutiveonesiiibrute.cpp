#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int maxlen = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int z = 0;
            int len = 0;
            for (int j = i; j < n; j++)
            {
                if (nums[j] == 0)
                    z++;

                if (z <= k)
                {
                    len = j - i + 1;
                    maxlen = max(len, maxlen);
                }
                else
                    break;
            }
        }
        return maxlen;
    }
};