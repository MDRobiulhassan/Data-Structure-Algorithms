#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& a, int target) {
        int l=0,r=a.size()-1;
        while(l<=r)
        {
            int mid=(l+r)/2;

            if(a[mid]==target)
                return true;
            if(a[l]==a[mid]&&a[mid]==a[r])
            {
                l=l+1;
                r=r-1;
                continue;
            }
            if(a[l]<=a[mid])
            {
                if(target>=a[l]&&target<=a[mid])
                    r=mid-1;
                else
                    l=mid+1;
            }
            else
            {
                if(target>=a[mid]&&target<=a[r])
                    l=mid+1;
                else
                    r=mid-1;
            }
        }
        return false;
    }
};