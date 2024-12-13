#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int> > subsets(vector<int> &nums)
    {
        vector<vector<int> > ans;
        int subsets = 1 << nums.size();

        for (int i = 0; i < subsets; i++)
        {
            vector<int> a;
            for (int j = 0; j < nums.size(); j++)
            {
                if (i & (1 << j))
                    a.push_back(nums[j]);
            }
            ans.push_back(a);
        }
        return ans;
    }
};