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

        int mv=INT_MIN,mk=-1;
        for(auto &it:a)
        {
            if(it.second>mv)
            {
                mv=it.second;
                mk=it.first;
            }
        }

        return mk;
    }
};