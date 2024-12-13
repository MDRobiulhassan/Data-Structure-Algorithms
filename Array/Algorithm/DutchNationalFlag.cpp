#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& a) {
        int low=0,mid=0,high=a.size()-1;

        //unosrted portion
        while(mid<=high)
        {
            if(a[mid]==0)
                swap(a[low++],a[mid++]);
            else if(a[mid]==1)
                mid++;
            else
                swap(a[mid],a[high--]);
        }
    }
};