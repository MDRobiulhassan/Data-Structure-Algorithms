#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target){
        int l = 0, r = nums.size() - 1;
        int ind = r+1;

        while (l <= r) {
            int mid = (l + r) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid]>= target) {
                ind = mid;
                r=mid-1;
            } else 
                l=mid+1;
        }
        return ind;
    }
};