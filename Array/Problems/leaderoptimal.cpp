//{ Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    // Function to find the leaders in the array.
public:
    vector<int> leaders(int n, int arr[])
    {
        vector<int> ans;
        for (int i = 0; i < n - 1; i++)
        {
            int count = 0;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] >= arr[j])
                    count++;
                else
                    break;
            }
            if (count == n - i - 1)
                ans.push_back(arr[i]);
        }
        ans.push_back(arr[n - 1]);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    long long t;
    cin >> t; // testcases
    while (t--)
    {
        long long n;
        cin >> n; // total size of array

        int arr[n];

        // inserting elements in the array
        for (long long i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution obj;
        // calling leaders() function
        vector<int> v = obj.leaders(n, arr);

        // printing elements of the vector
        // for (auto it = v.begin(); it != v.end(); it++) {
        //     cout << *it << " ";
        // }

        cout << endl;
    }
}

// } Driver Code Ends