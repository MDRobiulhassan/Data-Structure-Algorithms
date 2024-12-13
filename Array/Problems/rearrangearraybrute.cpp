#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        vector<int> pos, neg;
        int j = 0, k = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= 0)
                pos.push_back(nums[i]);
            else
                neg.push_back(nums[i]);
        }

        int i = 0;
        for (auto it : pos)
        {
            nums[i] = it;
            i += 2;
        }
        i = 1;
        for (auto it : neg)
        {
            nums[i] = it;
            i += 2;
        }
        return nums;
    }
};