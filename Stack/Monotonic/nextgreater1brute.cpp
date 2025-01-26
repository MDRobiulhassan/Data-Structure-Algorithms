#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> pos;
        int n = nums1.size(), m = nums2.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (nums1[i] == nums2[j])
                {
                    pos.push_back(j);
                    break;
                }
            }
        }

        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++)
        {
            for (int j = pos[i]; j < m; j++)
            {
                if (nums2[j] > nums1[i])
                {
                    ans[i] = nums2[j];
                    break;
                }
            }
        }

        return ans;
    }
};