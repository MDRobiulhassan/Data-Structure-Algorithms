//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public: 
	int NthRoot(int n, int m)
	{
	    for(int i=1;i<=m;i++)
	    {
	        long long mult=1;
	        int j;
	        for(j=1;j<=n;j++)
	        {
	            mult=mult*i;
	        }
	        if(mult==m)
	            return i;
	        if(mult>m)
	            return -1;
	    }
	    return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends