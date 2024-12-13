#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &a)
    {
        vector<vector<int>> ans;
        sort(a.begin(), a.end());
        int n = a.size();

        for (int i = 0; i < n; i++)
        {
            if (ans.empty() || a[i][0] > ans.back()[1])
                ans.push_back(a[i]);
            else
                ans.back()[1] = max(ans.back()[1], a[i][1]);
        }

        return ans;
    }
};