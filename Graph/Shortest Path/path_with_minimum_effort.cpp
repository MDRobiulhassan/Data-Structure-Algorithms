#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int n = heights.size();
        int m = heights[0].size();

        // Distance matrix to store the minimum effort needed to reach each cell
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;

        // Min-heap priority queue: {effort, {row, col}}
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        pq.push({0, {0, 0}}); // Start with (0,0) with effort 0

        // Directions: up, right, down, left
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            int effort = it.first;
            int r = it.second.first;
            int c = it.second.second;

            // If we reached the destination, return the effort
            if (r == n - 1 && c == m - 1)
                return effort;

            for (int i = 0; i < 4; i++)
            {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                // Check bounds
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m)
                {
                    // Compute the new effort: max of current and height difference
                    int newEffort = max(effort, abs(heights[r][c] - heights[nrow][ncol]));

                    // If we found a smaller effort path, update and push to pq
                    if (newEffort < dist[nrow][ncol])
                    {
                        dist[nrow][ncol] = newEffort;
                        pq.push({newEffort, {nrow, ncol}});
                    }
                }
            }
        }

        return 0; // theoretically never reached
    }
};
