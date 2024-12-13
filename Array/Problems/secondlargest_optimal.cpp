//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int a[], int n) {
	    int l=a[0],sl=-1;
	    for(int i=0;i<n;i++)
	    {
	        if(a[i]>l)
	        {
	            sl=l;
	            l=a[i];
	        }
	        else if(a[i]>sl&&a[i]<l)
	            sl=a[i];
	    }
	    return sl;
	}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends