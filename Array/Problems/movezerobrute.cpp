#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& a) {
        int n = a.size();
        vector<int> b;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]!=0)
                b.push_back(a[i]);
            else
                count++;
        }
        for(int i=0;i<n;i++)
        {
            if(i<b.size())
                a[i]=b[i];
            else
                a[i]=0;
        }
    }
};