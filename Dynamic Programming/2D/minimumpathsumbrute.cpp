#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minSum(int i, int j, vector<vector<int> > &grid)
    {
        if (i == 0 && j == 0)
            return grid[0][0];
        if (i < 0 || j < 0)
            return 1e9;

        int l = grid[i][j] + minSum(i - 1, j, grid);
        int u = grid[i][j] + minSum(i, j - 1, grid);

        return min(l, u);
    }

    int minPathSum(vector<vector<int> > &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        return minSum(n - 1, m - 1, grid);
    }
};