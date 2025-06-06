#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countPaths(int i, int j, vector<vector<int> > &obstacleGrid)
    {
        if (i < 0 || j < 0 || obstacleGrid[i][j] == 1)
            return 0;
        if (i == 0 && j == 0)
            return 1;

        int l = countPaths(i, j - 1, obstacleGrid);
        int u = countPaths(i - 1, j, obstacleGrid);
        return l + u;
    }

    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid)
    {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[n - 1][m - 1] == 1)
            return 0;
        return countPaths(n - 1, m - 1, obstacleGrid);
    }
};