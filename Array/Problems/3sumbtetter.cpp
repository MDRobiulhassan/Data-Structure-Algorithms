#include <bits/stdc++.h>
using namespace std;
 class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        set<vector<int>> a;
        for (int i = 0; i < n; i++)
        {
            set<int> h;
            for (int j = i + 1; j < n; j++)
            {
                int k = -(nums[i] + nums[j]);

                if (h.find(k) != h.end())
                {
                    vector<int> triplet = {nums[i], nums[j], k};
                    sort(triplet.begin(), triplet.end());
                    a.insert(triplet);
                }
                h.insert(nums[j]);
            }
        }
        vector<vector<int>> result(a.begin(), a.end());
        return result;
    }
};