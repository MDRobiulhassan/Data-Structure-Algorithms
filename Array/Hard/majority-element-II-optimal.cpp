#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        // Initialize two candidates and their counters
        int candidate1 = 0, candidate2 = 1;
        int count1 = 0, count2 = 0;

        // First pass: find two potential majority candidates
        for (int num : nums)
        {
            if (num == candidate1)
                count1++; // Increase count if it matches candidate1
            else if (num == candidate2)
                count2++; // Increase count if it matches candidate2

            else if (count1 == 0)
            {
                // Replace candidate1 if its count is zero
                candidate1 = num;
                count1 = 1;
            }
            else if (count2 == 0)
            {
                // Replace candidate2 if its count is zero
                candidate2 = num;
                count2 = 1;
            }
            else
            {
                // Cancel one vote from both candidates
                count1--;
                count2--;
            }
        }

        // Reset counters to verify actual frequencies
        count1 = 0;
        count2 = 0;

        // Second pass: count actual occurrences of both candidates
        for (int num : nums)
        {
            if (num == candidate1)
                count1++;
            else if (num == candidate2)
                count2++;
        }

        vector<int> ans;
        int n = nums.size();

        // Include candidate1 if it appears more than n / 3 times
        if (count1 > n / 3)
            ans.push_back(candidate1);

        // Include candidate2 if it appears more than n / 3 times
        if (count2 > n / 3)
            ans.push_back(candidate2);

        return ans;
    }
};
