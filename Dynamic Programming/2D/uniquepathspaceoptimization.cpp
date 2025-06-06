#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid)
    {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1 || obstacleGrid[n - 1][m - 1] == 1)
            return 0; // No path possible.

        vector<int> prev(m, 0);

        // Initialize first row
        for (int j = 0; j < m; j++)
        {
            if (obstacleGrid[0][j] == 1)
                break;
            prev[j] = 1;
        }

        for (int i = 1; i < n; i++)
        {
            vector<int> curr(m, 0);
            if (obstacleGrid[i][0] == 0)
                curr[0] = prev[0];

            for (int j = 1; j < m; j++)
            {
                if (obstacleGrid[i][j] == 1)
                    curr[j] = 0;
                else
                    curr[j] = curr[j - 1] + prev[j];
            }
            prev = curr;
        }

        return prev[m - 1];
    }
};
