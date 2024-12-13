//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int firstoccurence(int arr[], int n, int x)
	{
	    int l=0,r=n-1;
	    int first=-1;
	    while(l<=r)
	    {
	        int mid=(l+r)/2;
	        if(arr[mid]==x)
	        {
	            r=mid-1;
	            first=mid;
	        }
	        else if(arr[mid]<x)
	            l=mid+1;
	        else
	            r=mid-1;
	    }
	    
	    return first;
	}
	
	int lastoccurence(int arr[],int n,int x)
	{
	    int l=0,r=n-1;
	    int last=-1;
	    while(l<=r)
	    {
	        int mid=(l+r)/2;
	        if(arr[mid]==x)
	        {
	            l=mid+1;
	            last=mid;
	        }
	        else if(arr[mid]<x)
	            l=mid+1;
	        else
	            r=mid-1;
	    }
	    return last;
	}
	
	int count(int arr[], int n, int x) {
	    int cnt=0;
	    int first=firstoccurence(arr, n,x);
	    int last=lastoccurence(arr, n, x);
	    
	    if(first!=-1&&last!=-1)
	        cnt=last-first+1;
	    else
	        cnt=0;
	    return cnt;
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends