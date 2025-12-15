#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size(); 

        // If the start or end cell is blocked, path is impossible
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0)
            return -1;

        // Edge case: single cell grid which is open (already at destination)
        if (n == 1 && grid[0][0] == 0)
            return 1;

        // Queue for BFS -> stores {distance, {row, col}}
        queue<pair<int, pair<int, int>>> q;

        // Distance matrix initialized to large value (infinity)
        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        dist[0][0] = 1;      // distance to start cell is 1
        q.push({1, {0, 0}}); // push start cell with distance 1

        // Directions for 8 possible moves
        int drow[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dcol[] = {0, 1, 1, 1, 0, -1, -1, -1};

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            int dis = it.first;       // current distance from source
            int r = it.second.first;  // current row
            int c = it.second.second; // current column

            // Explore all 8 directions
            for (int i = 0; i < 8; i++)
            {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                // Check boundaries and open cell condition
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n &&
                    grid[nrow][ncol] == 0 && dis + 1 < dist[nrow][ncol])
                {

                    // Update distance
                    dist[nrow][ncol] = dis + 1;

                    // If destination reached, return distance
                    if (nrow == n - 1 && ncol == n - 1)
                        return dist[nrow][ncol];

                    // Push next cell with updated distance
                    q.push({dist[nrow][ncol], {nrow, ncol}});
                }
            }
        }

        // If destination cannot be reached
        return -1;
    }
};
