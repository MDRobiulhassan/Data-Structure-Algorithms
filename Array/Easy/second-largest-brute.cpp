#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int mx=arr[n-1];
        
        for(int i=n-1;i>=0;i--)
        {
            if(arr[i]!=mx)
                return arr[i];
        }
        
        return -1;
    }
};