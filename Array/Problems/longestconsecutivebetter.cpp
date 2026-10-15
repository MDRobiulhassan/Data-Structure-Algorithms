#include <bits/stdc++.h>
using namespace std;

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // arr[] : the input array
    // N : size of the array arr[]

    // Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        int count = 0, len = 1;
        int lastsmaller = INT_MIN;
        sort(arr, arr + N);
        for (int i = 0; i < N; i++)
        {
            if (arr[i] - 1 == lastsmaller)
            {
                count++;
                lastsmaller = arr[i];
            }
            else if (arr[i] != lastsmaller)
            {
                count = 1;
                lastsmaller = arr[i];
            }
            len = max(len, count);
        }
        return len;
    }
};