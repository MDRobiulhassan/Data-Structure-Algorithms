#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0, presum = 0;
        map<int, int> m;
        m[0] = 1;
        for (int i = 0; i < n; i++) {
            presum += nums[i]; // Add current element to the running prefix sum

            int remove = presum - k; // Determine the required prefix sum to
                                     // form the subarray sum k

            count += m[remove]; // Increment count by the number of times
                                // the required prefix sum has occurred

            m[presum]++; // Update the frequency of the current prefix sum in
                         // the map
        }
        return count;
    }
};