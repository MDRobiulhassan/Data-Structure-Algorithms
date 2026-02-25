#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> replaceWithRank(vector<int> &arr, int N)
    {
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> rank;
        int r = 1;

        for (int i = 0; i < N; i++)
        {
            if (rank.find(sorted[i]) == rank.end())
            { // first occurrence only
                rank[sorted[i]] = r++;
            }
        }

        vector<int> ans(N);
        for (int i = 0; i < N; i++)
            ans[i] = rank[arr[i]];

        return ans;
    }
};