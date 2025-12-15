#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();

        // Min-heap that stores: (time required to reach this cell, (row, col))
        // We use greater<> to make it a min-heap.
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>>
            pq;

        // Visited array to avoid revisiting cells
        vector<vector<int>> vis(n, vector<int>(n, 0));

        // Start from (0,0) at time = grid[0][0]
        pq.push({grid[0][0], {0, 0}});

        // Directions: up, right, down, left
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        while (!pq.empty())
        {
            // Extract the cell with minimum time requirement
            auto it = pq.top();
            pq.pop();

            int t = it.first;         // Current time needed
            int r = it.second.first;  // Row
            int c = it.second.second; // Column

            // If this cell is already processed, skip
            if (vis[r][c])
                continue;
            vis[r][c] = 1; // Mark as visited

            // If we reached the bottom-right cell, return the time
            if (r == n - 1 && c == n - 1)
                return t;

            // Explore all 4 directions
            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i]; // New row
                int nc = c + dc[i]; // New column

                // Check boundaries + not visited
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !vis[nr][nc])
                {
                    // To enter (nr, nc), the water must rise to at least grid[nr][nc]
                    // The time taken to reach here = max of current time and elevation
                    int newt = max(t, grid[nr][nc]);

                    // Push into priority queue
                    pq.push({newt, {nr, nc}});
                }
            }
        }

        return -1; // Should never reach here logically
    }
};
