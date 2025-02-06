#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void subsetsum(int i, vector<int> &candidates, vector<vector<int> > &ans,
                   vector<int> temp, int target)
    {
        if (i == candidates.size())
        {
            if (target == 0)
                ans.push_back(temp);
            return;
        }

        if (candidates[i] <= target)
        {
            temp.push_back(candidates[i]);
            subsetsum(i, candidates, ans, temp, target - candidates[i]);
            temp.pop_back();
        }

        subsetsum(i + 1, candidates, ans, temp, target);
    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int> > ans;
        vector<int> temp;

        subsetsum(0, candidates, ans, temp, target);
        return ans;
    }
};