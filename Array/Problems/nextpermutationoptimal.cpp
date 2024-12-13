#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind = -1,n=nums.size();

        //finding break point
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                ind = i;
                break;
            }
        }

        //if no break point found then it was the last pemuation of the array
        //reverse it to find the first permutation
        if (ind == -1)
            reverse(nums.begin(), nums.end());

        //if break point exist find the next greater element 
        else {
            for (int i = n - 1; i > ind; i--) {
                if (nums[i] > nums[ind]) {
                    swap(nums[i], nums[ind]);
                    break;
                }
            }
            reverse(nums.begin() + ind + 1, nums.end());
        }
    }
};