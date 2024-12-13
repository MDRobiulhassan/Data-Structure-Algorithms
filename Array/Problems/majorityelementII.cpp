#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }

        for(auto it:m)
        {
            if(it.second>nums.size()/3)
                ans.push_back(it.first);
        }

        return ans;

    }
};