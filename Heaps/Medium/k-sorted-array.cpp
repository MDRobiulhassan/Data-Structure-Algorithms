#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string isKSortedArray(int arr[], int n, int k)
    {
        vector<int> sorted(arr, arr + n);
        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> idx; // element -> its sorted index
        for (int i = 0; i < n; i++)
        {
            idx[sorted[i]] = i;
        }

        for (int i = 0; i < n; i++)
        {
            if (abs(i - idx[arr[i]]) > k)
                return "No";
        }

        return "Yes";
    }
};