#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int sum = 0, len = 0;
        int i,j;
        for (i = 0; i < n; i++) {
            sum=0;
            for (j = i; j < n; j++) {
                sum += nums[j];
                if (sum == k)
                    len++;
            }
            
        }
        return len;
    }
};