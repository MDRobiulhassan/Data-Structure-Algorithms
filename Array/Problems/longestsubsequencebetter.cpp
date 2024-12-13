#include <bits/stdc++.h>
using namespace std;

// Class containing the function to find the length of the longest subarray with sum K
class Solution
{
public:
    int lenOfLongSubarr(int A[], int N, int K)
    {
        map<long long, int> pf; // Map to store the prefix sums and their first occurrence indices
        long long sum = 0;      // Variable to store the cumulative sum
        int maxlen = 0;         // Variable to store the maximum length of the subarray with sum K

        for (int i = 0; i < N; i++)
        {
            sum += A[i]; // Update the cumulative sum

            // If the cumulative sum matches K, the length will be from 0 to i
            if (sum == K)
                maxlen = max(maxlen, i + 1);

            long long rem = sum - K; // Calculate the remaining sum needed to form sum K

            // When the sum is larger than K, check if we have a previous prefix sum that would make the current sum equal to K when subtracted
            if (pf.find(rem) != pf.end())
            {
                int len = i - pf[rem];     // Calculate the length of the subarray
                maxlen = max(maxlen, len); // Update maxlen if a longer subarray is found
            }

            // If the sum is not already in the map, add it with the current index
            // Ensure that the index does not get replaced if the sum already exists
            if (pf.find(sum) == pf.end())
                pf[sum] = i;
        }

        return maxlen; // Return the maximum length of the subarray with sum K
    }
};

int main()
{
    // Code to test the lenOfLongSubarr function
    int t;
    cin >> t; // Number of test cases
    while (t--)
    {
        int n, k;
        cin >> n >> k; // Size of the array and the sum K
        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i]; // Input the array elements

        Solution ob;
        cout << ob.lenOfLongSubarr(a, n, k) << endl; // Output the result for each test case
    }

    return 0;
}
