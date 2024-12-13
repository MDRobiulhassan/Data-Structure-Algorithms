//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        int xr = 0;

        // Step 1: XOR all array elements and numbers from 1 to n
        for (int i = 0; i < n; i++) {
            xr ^= arr[i];
            xr ^= (i + 1);
        }

        // Step 2: Find the rightmost set bit in xr
        int mask = xr & ~(xr - 1);

        // Initialize variables to store the two unique sets
        int x = 0, y = 0;

        // Step 3: Divide elements into two sets based on the rightmost set bit
        for (int i = 0; i < n; i++) {
            if (arr[i] & mask) {
                x ^= arr[i];
            } else {
                y ^= arr[i];
            }
        }
        
        // Apply the same division for numbers 1 to n
        for (int i = 1; i <= n; i++) {
            if (i & mask) {
                x ^= i;
            } else {
                y ^= i;
            }
        }

        // Step 4: Determine which of x or y is the repeating element
        int countX = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == x) countX++;
        }

        // If countX is 2, x is the repeating element and y is the missing element
        if (countX == 2) {
            return {x, y};
        }
        // Otherwise, y is the repeating element and x is the missing element
        return {y, x};
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends