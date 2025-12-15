#include <bits/stdc++.h>
using namespace std;

class DisjoinSet
{
    vector<int> rank, parent;

public:
    // Constructor: initialize DSU with n nodes
    DisjoinSet(int n)
    {
        rank.resize(n + 1, 0); // rank = height of tree
        parent.resize(n + 1);

        // each node is its own parent (initially)
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    // Find ultimate parent (with path compression)
    int findUPar(int node)
    {
        if (node == parent[node])
            return node;

        // Path compression: attach node directly to root
        return parent[node] = findUPar(parent[node]);
    }

    // Union by rank (attach smaller height tree to bigger height tree)
    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u); // ultimate parent of u
        int ulp_v = findUPar(v); // ultimate parent of v

        if (ulp_u == ulp_v)
            return; // already in the same set

        // attach smaller rank tree to larger rank tree
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            // both ranks are same → choose one as parent
            parent[ulp_v] = ulp_u;

            // increase rank of the new root
            rank[ulp_u]++;
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    DisjoinSet ds(7);

    // Make unions
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    // Before connecting (3, 7)
    if (ds.findUPar(3) == ds.findUPar(7))
        cout << "Same\n";
    else
        cout << "Not Same\n";

    // Connect 3 and 7
    ds.unionByRank(3, 7);

    // After union they should be same
    if (ds.findUPar(3) == ds.findUPar(7))
        cout << "Same\n";
    else
        cout << "Not Same\n";

    return 0;
}
