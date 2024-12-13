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
	    sort(a,a+n);
	    if(a[n-2]!=a[n-1])
	        return a[n-2];
	    int sl=a[n-2];
	    for(int i=n-3;i>=0;i--)
	    {
	        if(sl!=a[i])
	            return a[i];
	    }
	    return -1;
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