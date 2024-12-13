#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> a;

        int l = 0, r = 0;
        int i = 0;
        while (l < m && r < n)
        {
            if (nums1[l] <= nums2[r])
                a.push_back(nums1[l++]);
            else
                a.push_back(nums2[r++]);
        }

        while (l < m)
            a.push_back(nums1[l++]);
        while (r < n)
            a.push_back(nums2[r++]);

        i = 0;
        for (auto it : a)
        {
            nums1[i++] = it;
        }
    }
};