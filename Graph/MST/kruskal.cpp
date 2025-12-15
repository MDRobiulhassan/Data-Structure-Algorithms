#include <bits/stdc++.h>
using namespace std;

// User function Template for C++
class DisjointSet
{
    vector<int> size, parent;

public:
    // Constructor: initializes DSU with n nodes
    DisjointSet(int n)
    {
        size.resize(n + 1); // size array 
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i; // each node is its own parent
        
    }

    // Path compression: find ultimate parent
    int findUParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUParent(parent[node]); // compression
    }

    // Union by size: attach smaller tree to bigger tree
    void unionBySize(int u, int v)
    {
        int pu = findUParent(u);
        int pv = findUParent(v);

        if (pu == pv)
            return; // already in same set → do nothing

        // attach smaller set into bigger set
        if (size[pu] >= size[pv])
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};

class Solution
{
public:
    int kruskalsMST(int V, vector<vector<int>> &edges)
    {

        // Step 1: Sort edges by weight (Kruskal requirement)
        sort(edges.begin(), edges.end(),
             [](vector<int> &a, vector<int> &b)
             {
                 return a[2] < b[2]; // compare by weight
             });

        DisjointSet ds(V);
        int mstwt = 0; // stores MST total weight

        // Step 2: Iterate through sorted edges
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            // Step 3: If adding this edge doesn't create a cycle
            if (ds.findUParent(u) != ds.findUParent(v))
            {
                mstwt += wt;          // include the weight
                ds.unionBySize(u, v); // merge the sets
            }
        }

        // Step 4: Final MST weight
        return mstwt;
    }
};
