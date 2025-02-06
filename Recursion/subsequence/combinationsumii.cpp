#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void subsetsum(int i, vector<vector<int> > &ans, vector<int> &temp,
                   vector<int> &candidates, int target)
    {
        if (target == 0)
        {
            ans.push_back(temp);
            return;
        }

        for (int j = i; j < candidates.size(); j++)
        {
            if (j > i && candidates[j] == candidates[j - 1])
                continue;
            if (candidates[j] > target)
                break;
            temp.push_back(candidates[j]);
            subsetsum(j + 1, ans, temp, candidates, target - candidates[j]);
            temp.pop_back();
        }
    }

    vector<vector<int> > combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int> > ans;
        vector<int> temp;

        sort(candidates.begin(), candidates.end());
        subsetsum(0, ans, temp, candidates, target);
        return ans;
    }
};