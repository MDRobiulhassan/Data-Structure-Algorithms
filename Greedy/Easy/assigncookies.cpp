#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        int n = s.size(), m = g.size();
        int l = 0, r = 0;

        sort(s.begin(), s.end());
        sort(g.begin(), g.end());

        while (l < n && r < m)
        {
            if (s[l] >= g[r])
                r++;
            l++;
        }

        return r;
    }
};