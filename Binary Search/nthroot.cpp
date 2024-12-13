//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public: 
	
	int multiplication(int mid,int m,int n)
    {
        long long mult=1;
	    int i;
        for(i=1;i<=n;i++)
        {
            mult=mult*mid;
            if(mult>m)
                return 0;
        }
        if(mult==m)
            return 1;
        return 2;
    }
	
	int NthRoot(int n, int m)
	{
	    int l=1,r=m;
	    
	    while(l<=r)
	    {
	        int mid=(l+r)/2;
	        if(multiplication(mid,m,n)==1)
	            return mid;
	        if(multiplication(mid,m,n)==0)
	            r=mid-1;
	        else
	            l=mid+1;
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