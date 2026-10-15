#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &a, vector<int> &b)
    {
        vector<int> ans;
        unordered_set<int> st(a.begin(), a.end());

        for (auto it : b)
        {
            if (st.count(it))
            {
                ans.push_back(it);
                st.erase(it);
            }
        }

        return ans;
    }
};