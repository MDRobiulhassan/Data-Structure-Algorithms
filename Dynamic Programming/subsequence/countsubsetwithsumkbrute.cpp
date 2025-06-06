#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int subsetSum(int i, vector<int> &arr, int target)
    {
        if (i < 0)
            return (target == 0);

        int take = 0;
        if (target >= arr[i])
            take = subsetSum(i - 1, arr, target - arr[i]);
        int nottake = subsetSum(i - 1, arr, target);

        return take + nottake;
    }

    int perfectSum(vector<int> &arr, int target)
    {
        return subsetSum(arr.size() - 1, arr, target);
    }
};