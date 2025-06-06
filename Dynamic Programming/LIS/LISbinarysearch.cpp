#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();

        // LIS will store the smallest possible tail of all increasing subsequences of different lengths
        vector<int> LIS;

        // Start with the first element
        LIS.push_back(nums[0]);
        int len = 1; // Initial length of LIS is 1

        for (int i = 1; i < n; i++)
        {
            if (nums[i] > LIS.back())
            {
                // If current element is greater than last element in LIS,
                // it can extend the longest increasing subsequence so far
                LIS.push_back(nums[i]);
                len++;
            }
            else
            {
                // Find the first element in LIS which is >= nums[i]
                // and replace it with nums[i] to keep LIS elements as small as possible
                int ind = lower_bound(LIS.begin(), LIS.end(), nums[i]) - LIS.begin();
                LIS[ind] = nums[i];
            }
        }

        // The size of LIS array will give the length of the longest increasing subsequence
        return len;
    }
};
