#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void generatesubsets(int i, vector<vector<int> > &ans, vector<int> &temp,
                         vector<int> &nums)
    {
        if (i == nums.size())
        {
            ans.push_back(temp);
            return;
        }

        // take
        temp.push_back(nums[i]);
        generatesubsets(i + 1, ans, temp, nums);

        // not take
        temp.pop_back();
        generatesubsets(i + 1, ans, temp, nums);
    }

    vector<vector<int> > subsets(vector<int> &nums)
    {
        vector<vector<int> > ans;
        vector<int> temp;

        generatesubsets(0, ans, temp, nums);
        return ans;
    }
};