#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);   // dp[i] stores the length of the largest divisible subset ending at index i
        vector<int> hash(n, 1); // hash[i] stores the index of the previous element in the subset

        sort(nums.begin(), nums.end()); // Sort to ensure nums[i] >= nums[j] for i > j

        for (int i = 0; i < n; i++)
        {
            hash[i] = i; // initialize hash to point to self
            for (int j = 0; j < i; j++)
            {
                // If nums[i] is divisible by nums[j] and we get a longer subset
                if (nums[i] % nums[j] == 0 && 1 + dp[j] > dp[i])
                {
                    dp[i] = 1 + dp[j]; // update the length of the subset
                    hash[i] = j;       // update the previous index
                }
            }
        }

        int ans = -1;
        int last = -1;

        // Find the index with the maximum subset length
        for (int i = 0; i < n; i++)
        {
            if (dp[i] > ans)
            {
                ans = dp[i];
                last = i;
            }
        }

        vector<int> LDS;           // Vector to store the result subset
        LDS.push_back(nums[last]); // Start from the last index

        // Reconstruct the subset using the hash array
        while (hash[last] != last)
        {
            last = hash[last];         // Move to previous index
            LDS.push_back(nums[last]); // Add element to result
        }

        reverse(LDS.begin(), LDS.end()); // The subset was built backwards, so reverse it

        return LDS;
    }
};
