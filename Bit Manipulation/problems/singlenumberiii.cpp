//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)
    {
        long long int xr = 0;
        for (int i = 0; i < N; i++)
            xr = xr ^ Arr[i];

        long long int rm = xr & (-xr);

        long long int b1 = 0, b2 = 0;
        for (int i = 0; i < N; i++)
        {
            if (Arr[i] & rm)
                b1 = b1 ^ Arr[i];
            else
                b2 = b2 ^ Arr[i];
        }

        if (b1 > b2)
            return {b1, b2};
        return {b2, b1};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int N;
        cin >> N;
        long long int Arr[N];
        for (long int i = 0; i < N; i++)
            cin >> Arr[i];
        Solution ob;
        vector<long long int> ans = ob.twoOddNum(Arr, N);
        for (long long int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;

        cout << "~" << "\n";
    }
    return 0;
}
// } Driver Code Ends