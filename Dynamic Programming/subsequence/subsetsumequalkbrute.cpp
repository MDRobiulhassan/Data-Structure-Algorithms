#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool subsetSum(int i, vector<int> &arr, int target)
    {
        if (target == 0)
            return true;
        if (i == 0)
            return arr[0] == target;

        bool nottake = subsetSum(i - 1, arr, target);
        bool take = false;
        if (arr[i] <= target)
            take = subsetSum(i - 1, arr, target - arr[i]);

        return take || nottake;
    }

    bool isSubsetSum(vector<int> &arr, int target)
    {
        return subsetSum(arr.size() - 1, arr, target);
    }
};
