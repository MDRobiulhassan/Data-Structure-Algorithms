#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(int n, vector<int> &arr, int k, int i, int sum)
    {
        if (i == n)
            return sum == k;

        bool sum1 = check(n, arr, k, i + 1, sum + arr[i]);
        bool sum2 = check(n, arr, k, i + 1, sum);

        return sum1 || sum2;
    }

    bool checkSubsequenceSum(int n, vector<int> &arr, int k)
    {
        return check(n, arr, k, 0, 0);
    }
};