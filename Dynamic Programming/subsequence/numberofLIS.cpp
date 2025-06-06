#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();

        // dp[i] = length of Longest Increasing Subsequence (LIS) ending at index i
        // cnt[i] = number of such LIS ending at index i
        vector<int> dp(n, 1);
        vector<int> cnt(n, 1);

        int mx = 1; // keeps track of the maximum length of LIS found so far

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                // if we can extend the subsequence ending at j with nums[i]
                if (nums[i] > nums[j])
                {
                    // Case 1: a longer subsequence is found
                    if (1 + dp[j] > dp[i])
                    {
                        dp[i] = 1 + dp[j]; // update the length
                        cnt[i] = cnt[j];   // take the count from dp[j]
                    }
                    // Case 2: another way to form same length subsequence
                    else if (1 + dp[j] == dp[i])
                    {
                        cnt[i] += cnt[j]; // accumulate the count
                    }
                }
            }
            mx = max(mx, dp[i]); // update the global max LIS length
        }

        int count = 0;

        // Sum the counts for all indices where LIS length is equal to max length
        for (int i = 0; i < n; i++)
        {
            if (dp[i] == mx)
                count += cnt[i];
        }

        return count; // total number of LIS of max length
    }
};
