#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Helper function to count the number of subarrays with sum at most 'goal'
    int f(vector<int> &nums, int goal)
    {
        if (goal < 0)
            return 0; // No subarrays possible with negative sum

        int n = nums.size();
        int l = 0, r = 0; // Sliding window pointers
        int sum = 0;      // Current sum of the window
        int count = 0;    // Count of valid subarrays

        while (r < n)
        {
            sum += nums[r]; // Expand window to the right

            // Shrink window from the left if the sum exceeds the goal
            while (sum > goal)
                sum -= nums[l++];

            // Add number of valid subarrays ending at index r
            count += (r - l + 1);

            r++; // Move right pointer forward
        }

        return count;
    }

    // Main function to count subarrays with sum exactly equal to 'goal'
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        // Count subarrays with sum at most goal
        // Subtract subarrays with sum at most goal - 1
        // The difference gives the count of subarrays with exact sum = goal
        return f(nums, goal) - f(nums, goal - 1); //first one is <=goal
    }
};
