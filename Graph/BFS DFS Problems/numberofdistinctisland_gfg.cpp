#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int row, int col, vector<vector<int> > &grid, vector<vector<int> > &vis,
             vector<pair<int, int> > &shape, int baseRow, int baseCol)
    {
        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1; // mark current cell as visited
        // store relative position to the first cell of this island
        shape.push_back({row - baseRow, col - baseCol});

        int drow[] = {-1, 0, 1, 0}; // movement in 4 directions (up, right, down, left)
        int dcol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + drow[i]; // neighbor row
            int ncol = col + dcol[i]; // neighbor column

            // check bounds, unvisited, and is land (1)
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                !vis[nrow][ncol] && grid[nrow][ncol] == 1)
                dfs(nrow, ncol, grid, vis, shape, baseRow, baseCol);
            // recursively visit neighbor
        }
    }

    // Main function to count distinct islands
    int countDistinctIslands(vector<vector<int> > &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int> > vis(n, vector<int>(m, 0));

        set<vector<pair<int, int> > > dis; // set to store distinct island shapes

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // if unvisited land
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    // stores shape of current island
                    vector<pair<int, int> > shape;

                    // perform DFS and record shape
                    dfs(i, j, grid, vis, shape, i, j);

                    // insert shape into set; duplicates automatically ignored
                    dis.insert(shape);
                }
            }
        }
        return dis.size(); // total number of distinct islands
    }
};
