#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> a;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {

            // ensuring nums[i] not the same element after increment
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1;
            int k = n - 1;

            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0)
                    j++;
                else if (sum > 0)
                    k--;
                else
                {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    a.push_back(temp);
                    j++;
                    k--;

                    // ensuring nums[j] and nums[k] not the same element after increment
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }
        return a;
    }
};