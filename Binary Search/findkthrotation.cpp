//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
    //find the minimum ,beacuse where the
    //mininum is located array is rotated as the index times
  public:
    int findKRotation(vector<int> &a) {
        int l=0,r=a.size()-1;
        int ans=INT_MAX;
        int ind=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            
            if(a[l]<=a[mid])
            {
                if(a[l]<ans)
                {
                    ans=a[l];
                    ind=l;
                }
                l=mid+1;
            }
            else
            {
                if(a[mid]<=a[r])
                {
                    ans=a[mid];
                    ind=mid;
                }
                r=mid-1;
            }
        }
       
        
        return ind;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        Solution ob;
        int res = ob.findKRotation(arr);
        cout << res << endl;
    }
}
// } Driver Code Ends