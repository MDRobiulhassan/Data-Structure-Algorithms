#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        set<int> st;

        for (auto it : nums)
            st.insert(it);

        nums.clear();
        for (auto it : st)
            nums.push_back(it);
        return st.size();
    }
};
