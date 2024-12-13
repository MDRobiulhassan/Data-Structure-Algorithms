#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); // Sort the array to facilitate two-pointer approach
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            // Skip duplicate elements for the first number
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n; j++)
            {
                // Skip duplicate elements for the second number
                if (j != i + 1 && nums[j] == nums[j - 1])
                    continue;
                int k = j + 1, l = n - 1;
                while (k < l)
                {
                    // Use long long to avoid overflow
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                    if (sum < target)
                        k++;
                    else if (sum > target)
                        l--;
                    else
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        result.push_back(temp);
                        k++, l--;
                        // Skip duplicate elements for the third and fourth numbers
                        while (k < l && nums[k] == nums[k - 1])
                            k++;
                        while (k < l && nums[l] == nums[l + 1])
                            l--;
                    }
                }
            }
        }

        return result;
    }
};