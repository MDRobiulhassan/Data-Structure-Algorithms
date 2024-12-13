#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        int l = 0, r = 1;

        for(int i=0;i<nums.size();i++) {
            if (nums[i] >= 0) {
                ans[l]=nums[i];
                l += 2;
            } else
            {
                ans[r]=nums[i];
                r+=2;
            }
        }

        return ans;
    }
};