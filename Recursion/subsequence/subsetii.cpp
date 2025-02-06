#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void subsets(int i, vector<int> &nums, vector<vector<int> > &ans, vector<int> temp)
    {
        if (i == nums.size())
        {
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        subsets(i + 1, nums, ans, temp);
        temp.pop_back();

        while (i + 1 < nums.size() && nums[i] == nums[i + 1])
            i++;
        subsets(i + 1, nums, ans, temp);
    }
    vector<vector<int> > subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int> > ans;
        vector<int> temp;

        sort(nums.begin(), nums.end());
        subsets(0, nums, ans, temp);
        return ans;
    }
};