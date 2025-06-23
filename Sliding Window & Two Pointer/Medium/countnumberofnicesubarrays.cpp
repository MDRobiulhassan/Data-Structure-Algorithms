#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int count(vector<int> &nums, int k)
    {
        if (k < 0)
            return 0; // No valid subarrays if k is negative

        int l = 0, r = 0;
        int sum = 0;
        int count = 0;
        int n = nums.size();

        while (r < n)
        {
            sum += nums[r] % 2; // Add 1 if the current number is odd

            // Shrink the window from the left if the number of odd numbers exceeds 'k'
            while (sum > k)
            {
                sum -= nums[l] % 2; // Remove the contribution of the left element
                l++;                // Move the left pointer forward
            }

            // All subarrays ending at index 'r' and starting from index 'l' to 'r' are valid
            count += (r - l + 1);
            r++; // Move the right pointer forward
        }

        return count; // Total subarrays with at most 'k' odd numbers
    }

    int numberOfSubarrays(vector<int> &nums, int k)
    {
        // Number of subarrays with exactly 'k' odd numbers =
        // (number of subarrays with at most 'k') - (number with at most 'k - 1')
        // The main goal is to convert the whole array into binary array
        // and we can apply the binary subarray sum solution
        return count(nums, k) - count(nums, k - 1);
    }
};
