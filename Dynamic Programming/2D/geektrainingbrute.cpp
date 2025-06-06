#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(int i, vector<vector<int> > &arr, int last)
    {
        if (i == 0)
        {
            int mx = 0;
            for (int j = 0; j < 3; j++)
            {
                if (j != last)
                    mx = max(mx, arr[0][j]);
            }
            return mx;
        }

        int mx = 0;
        for (int j = 0; j < 3; j++)
        {
            if (j != last)
            {
                int point = arr[i][j] + solve(i - 1, arr, j);
                mx = max(mx, point);
            }
        }
        return mx;
    }

    int maximumPoints(vector<vector<int> > &arr)
    {
        int n = arr.size();
        return solve(n - 1, arr, 3);
    }
};