#include <bits/stdc++.h>
using namespace std;

//the minimum will always be in the unsorted half

class Solution {
public:
    int findMin(vector<int>& a) {
       int l=0,r=a.size()-1;
        int mn=INT_MAX;

       while(l<=r)
       {
            int mid=(l+r)/2;

            if(a[l]<=a[mid])
            {
                mn=min(a[l],mn);
                l=mid+1;
            }
            else
            {
                mn=min(a[mid],mn);
                r=mid-1;
            }
       }

        return mn;
    }
};