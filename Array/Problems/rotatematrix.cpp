#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        int n=a.size();
        
        //transpose
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                swap(a[i][j],a[j][i]);
            }
        }

        //reverse row
        for(int i=0;i<n;i++)
        {
            reverse(a[i].begin(),a[i].end());
        }
    }
};