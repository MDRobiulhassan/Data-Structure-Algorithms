#include<bits/stdc++.h>
using namespace std;


// in case of non sorted array this is the optimal solutions
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ind;
        map<int,int> a;

        for(int i=0;i<nums.size();i++)
        {
            int rem=target-nums[i];

            if(a.find(rem)!=a.end())
            {
                ind.push_back(a[rem]);
                ind.push_back(i);
                break;
            }
            else
                a[nums[i]]=i;
        }

        return ind;
    }
};