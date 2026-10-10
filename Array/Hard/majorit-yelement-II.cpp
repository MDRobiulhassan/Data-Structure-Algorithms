#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> m;
        vector<int> ans;

        for (auto it : nums)
            m[it]++;

        for (auto it : m)
        {
            if (it.second > n / 3)
                ans.push_back(it.first);
        }

        return ans;
    }
};