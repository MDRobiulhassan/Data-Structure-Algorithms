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
            int start = a[i][0], end = a[i][1];

            if (!ans.empty() && end <= ans.back()[1])
                continue;

            for (int j = i + 1; j < n; j++)
            {
                if (a[j][0] <= end)
                    end = max(end, a[j][1]);
                else
                    break;
            }
            ans.push_back({start, end});
        }

        return ans;
    }
};