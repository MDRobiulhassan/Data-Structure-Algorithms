#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        unordered_set<int> st(nums1.begin(), nums1.end());

        for (auto it : nums2)
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