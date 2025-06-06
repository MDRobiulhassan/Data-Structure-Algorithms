#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countPath(int i, int j)
    {
        if (i == 0 && j == 0)
        {
            return 1;
        }

        int u = 0, l = 0;
        if (i - 1 >= 0)
            l += countPath(i - 1, j);
        if (j - 1 >= 0)
            u += countPath(i, j - 1);
        return l + u;
    }

    int uniquePaths(int m, int n) { return countPath(n - 1, m - 1); }
};