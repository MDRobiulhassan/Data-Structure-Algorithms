#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{

public:
    vector<int> size, parent;
    DisjointSet(int n)
    {
        size.resize(n + 1, 1);
        parent.resize(n + 1, 0);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if (pu == pv)
            return;
        if (size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }

        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution
{
private:
    // Check if a cell (nrow, ncol) is inside the grid boundaries
    bool isValid(int nrow, int ncol, int n)
    {
        return nrow >= 0 && nrow < n && ncol >= 0 && ncol < n;
    }

public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();

        // Initialize DSU for all cells in the grid
        DisjointSet ds(n * n);
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        // First pass: union all adjacent 1s in the grid
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 0)
                    continue;

                for (int i = 0; i < 4; i++)
                {
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];

                    if (isValid(nrow, ncol, n) && grid[nrow][ncol] == 1)
                    {
                        int node = row * n + col;
                        int adjNode = nrow * n + ncol;
                        ds.unionBySize(node, adjNode);
                    }
                }
            }
        }

        int mx = 0;
        // Second pass: try flipping each 0 to 1 and calculate potential island size
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 1)
                    continue;

                set<int> components; // track unique neighboring island roots
                for (int i = 0; i < 4; i++)
                {
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];

                    if (isValid(nrow, ncol, n) && grid[nrow][ncol] == 1)
                    {
                        int adjNode = nrow * n + ncol;
                        components.insert(ds.findUPar(adjNode));
                    }
                }

                int total = 0;
                for (auto it : components)
                {
                    total += ds.size[it]; // sum sizes of connected components
                }

                mx = max(mx, total + 1); // +1 for the flipped cell itself
            }
        }

        // Third pass: consider the case where all cells are 1s
        for (int i = 0; i < n * n; i++)
            mx = max(mx, ds.size[ds.findUPar(i)]);

        return mx;
    }
};
