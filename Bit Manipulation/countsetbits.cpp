//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // n: input to count the number of set bits
    // Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        int totalSetBits = 0;

        for (int i = 0; (1 << i) <= n; i++)
        {
            int blockSize = (1 << (i + 1));

            int completeBlocks = n / blockSize;

            totalSetBits += completeBlocks * (blockSize / 2);

            int remainder = n % blockSize;
            if (remainder >= (1 << i))
            {
                totalSetBits += remainder - (1 << i) + 1;
            }
        }

        return totalSetBits;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin >> t;   // input testcases
    while (t--) // while testcases exist
    {
        int n;
        cin >> n; // input n
        Solution ob;
        cout << ob.countSetBits(n) << endl; // print the answer

        cout << "~" << "\n";
    }
    return 0;
}

// } Driver Code Ends