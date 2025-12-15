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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    DisjointSet ds(7);

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
