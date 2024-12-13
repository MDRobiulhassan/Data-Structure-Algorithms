//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution
{
public:
    long long int floorSqrt(long long int n)
    {
        long long l = 1, r = n;
        long long mid, ans;
        while (l <= r)
        {
            mid = (l + r) / 2;
            long long mult = mid * mid;

            if (mult == n)
                return mid;
            if (mult > n)
                r = mid - 1;
            else
            {
                l = mid + 1;
                ans = mid;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends