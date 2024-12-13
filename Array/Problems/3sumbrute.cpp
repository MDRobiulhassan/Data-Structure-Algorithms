#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int ind = 0;
        int sum = 0;
        int n = nums.size();
        vector<vector<int>> a;
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    sum = 0;
                    sum = sum + nums[i] + nums[j] + nums[k];
                    if (sum == 0)
                    {
                        vector<int> triplet = {nums[i], nums[j], nums[k]};
                        sort(triplet.begin(), triplet.end());

                        if (find(a.begin(), a.end(), triplet) == a.end())
                        {
                            a.push_back(triplet);
                        }
                    }
                }
            }
        }

        return a;
    }
};