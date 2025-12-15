#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{

public:
    vector<int> size, parent;
    // Constructor: initialize DSU for n nodes
    DisjointSet(int n)
    {
        size.resize(n + 1, 0); // size[i] = size of component whose root is i
        parent.resize(n + 1);

        // Initially every node is its own parent
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    // Find ultimate parent with path compression
    int findUPar(int node)
    {
        if (node == parent[node])
            return node;

        // Path compression: directly connect node to root
        return parent[node] = findUPar(parent[node]);
    }

    // Union by size (attach smaller component to larger component)
    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u); // root of u
        int ulp_v = findUPar(v); // root of v

        if (ulp_u == ulp_v)
            return; // already in same set

        // attach smaller tree to the bigger tree
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u]; // increase component size
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
public:
    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        int maxRow = 0;
        int maxCol = 0;

        // Step 1: Find the maximum row and column index
        for (auto it : stones)
        {
            maxRow = max(maxRow, it[0]); // largest row index
            maxCol = max(maxCol, it[1]); // largest column index
        }

        // Step 2: Initialize DSU with enough size to hold both rows and columns
        DisjointSet ds(maxRow + maxCol + 2);

        // Step 3: Track all nodes (row and column indices used in DSU)
        unordered_set<int> stoneNodes;

        for (auto it : stones)
        {
            int rowNode = it[0];              // row node
            int colNode = maxRow + it[1] + 1; // shifted column node to avoid overlap with rows

            // Step 4: Union row and column nodes in DSU
            ds.unionBySize(rowNode, colNode);

            // Step 5: Insert nodes into the set to count components later
            stoneNodes.insert(rowNode);
            stoneNodes.insert(colNode);
        }

        // Step 6: Count number of connected components among used nodes
        int comp = 0;
        for (auto it : stoneNodes)
        {
            if (ds.findUPar(it) == it) // if node is its own root
                comp++;
        }

        // Step 7: Maximum stones removable = total stones - number of components
        return n - comp;
    }
};