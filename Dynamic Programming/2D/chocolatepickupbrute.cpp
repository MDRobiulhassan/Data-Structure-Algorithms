#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int pathSum(int i, int j1, int j2, vector<vector<int> > &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
            return -1e9;

        if (i == n - 1)
        {
            if (j1 == j2)
                return grid[i][j1];
            return grid[i][j1] + grid[i][j2];
        }

        int maxi = -1e9;
        for (int d1 = -1; d1 <= 1; d1++)
        {
            for (int d2 = -1; d2 <= 1; d2++)
            {
                if (j1 == j2)
                    maxi = max(maxi, grid[i][j1] + pathSum(i + 1, d1 + j1, d2 + j2, grid));
                else
                    maxi = max(maxi, grid[i][j1] + grid[i][j2] + pathSum(i + 1, d1 + j1, d2 + j2, grid));
            }
        }

        return maxi;
    }

    int solve(int n, int m, vector<vector<int> > &grid)
    {
        return pathSum(0, 0, m - 1, grid);
    }
};