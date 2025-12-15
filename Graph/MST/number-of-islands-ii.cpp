#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> size, parent;

public:
    DisjointSet(int n)
    {
        size.resize(n + 1, 0);
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
    // Check if (nrow, ncol) is within grid bounds
    bool isValid(int nrow, int ncol, int n, int m)
    {
        return nrow >= 0 && nrow < n && ncol >= 0 && ncol < m;
    }

public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {

        // DSU for n*m possible cells
        DisjointSet ds(n * m);

        vector<int> ans;
        int count = 0;

        // Visited matrix: 1 means land, 0 means water
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Process each operator
        for (auto it : operators)
        {
            int row = it[0];
            int col = it[1];

            // If already land, island count doesn't change
            if (vis[row][col] == 1)
            {
                ans.push_back(count);
                continue;
            }

            // Mark current cell as land
            vis[row][col] = 1;
            count++; // new island formed initially

            // 4 possible directions (up, right, down, left)
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};

            // Check all 4 neighbours
            for (int i = 0; i < 4; i++)
            {

                int nrow = row + dr[i];
                int ncol = col + dc[i];

                // If neighbour is valid and already land
                if (isValid(nrow, ncol, n, m))
                {
                    if (vis[nrow][ncol] == 1)
                    {

                        // Convert 2D -> 1D index for DSU
                        int node = row * m + col;
                        int adjNode = nrow * m + ncol;

                        // If neighbour belongs to a different island, union them
                        if (ds.findUPar(node) != ds.findUPar(adjNode))
                        {
                            ds.unionBySize(node, adjNode);
                            count--; // merging two islands reduces island count
                        }
                    }
                }
            }

            // Store number of islands after this operation
            ans.push_back(count);
        }

        return ans;
    }
};
