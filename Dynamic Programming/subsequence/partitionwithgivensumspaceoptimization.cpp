#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int countPartitions(vector<int> &arr, int d)
    {
        int total = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++)
            total += arr[i];

        if (total - d < 0 || (total - d) % 2 != 0)
            return 0;
        int target = (total - d) / 2;
        vector<int> prev(target + 1, 0);

        prev[0] = (arr[0] == 0) ? 2 : 1;
        if (arr[0] != 0 && arr[0] <= target)
            prev[arr[0]] = 1;

        for (int i = 1; i < n; i++)
        {
            vector<int> cur(target + 1, 0);
            for (int j = 0; j <= target; j++)
            {
                int nottake = prev[j];
                int take = 0;
                if (arr[i] <= j)
                    take = prev[j - arr[i]];

                cur[j] = take + nottake;
            }
            prev = cur;
        }

        return prev[target];
    }
};