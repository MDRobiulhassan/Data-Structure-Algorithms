#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int perfectSum(vector<int> &arr, int target)
    {
        vector<int> prev(target + 1, 0);

        prev[0] = 1;
        if (arr[0] <= target)
            prev[arr[0]] += 1;

        for (int i = 1; i < arr.size(); i++)
        {
            vector<int> cur(target + 1, 0);
            for (int j = 0; j <= target; j++)
            {
                int take = 0;
                if (j >= arr[i])
                    take = prev[j - arr[i]];
                int nottake = prev[j];

                cur[j] = take + nottake;
            }
            prev = cur;
        }
        return prev[target];
    }
};