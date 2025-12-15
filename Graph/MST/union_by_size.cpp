#include <bits/stdc++.h>
using namespace std;

class DisjoinSet
{
    vector<int> size, parent;

public:
    // Constructor: initialize DSU for n nodes
    DisjoinSet(int n)
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    DisjoinSet ds(7);

    // Build components
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    // Check connectivity before union(3,7)
    if (ds.findUPar(3) == ds.findUPar(7))
        cout << "Same";
    else
        cout << "Not Same";
    cout << '\n';

    // Now connect them
    ds.unionBySize(3, 7);

    // They must be in same component now
    if (ds.findUPar(3) == ds.findUPar(7))
        cout << "Same";
    else
        cout << "Not Same";

    return 0;
}
