#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int MCM(int i, int j, vector<int> &arr)
    {
        if (i == j)
            return 0;

        int mn = 1e9;
        for (int k = i; k < j; k++)
        {
            int steps = (arr[i - 1] * arr[j] * arr[k]) + MCM(i, k, arr) + MCM(k + 1, j, arr);

            mn = min(steps, mn);
        }
        return mn;
    }

    int matrixMultiplication(vector<int> &arr)
    {
        int n = arr.size();
        return MCM(1, n - 1, arr);
    }
};