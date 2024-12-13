#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        for (int i = 0; i < nums2.size(); i++)
        {
            nums1.push_back(nums2[i]);
        }

        sort(nums1.begin(), nums1.end());

        int s = nums1.size();

        if (s % 2 != 0)
        {
            int ind = s / 2;
            return double(nums1[ind]);
        }
        int ind1 = s / 2 - 1, ind2 = s / 2;
        double ans = double(nums1[ind1] + nums1[ind2]) / 2.0;
        return ans;
    }
};