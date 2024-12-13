#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> a;
        for(int i=0;i<nums.size();i++)
        {
            a[nums[i]]++;
        }

        for(auto &it:a)
        {
            if(it.second>(nums.size()/2))
                return it.first;
        }
        return 0;
    }
};