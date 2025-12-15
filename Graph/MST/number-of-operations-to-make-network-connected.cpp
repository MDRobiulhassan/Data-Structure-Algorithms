#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> size, parent;

public:
    DisjointSet(int n)
    {
        size.resize(n + 1, 0);
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUParent(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int pu = findUParent(u);
        int pv = findUParent(v);

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
public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        int m = connections.size();
        if (m < n - 1)
            return -1;

        DisjointSet ds(n);

        for (auto it : connections)
            ds.unionBySize(it[0], it[1]);
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (ds.findUParent(i) == i)
                count++;
        }

        return count - 1;
    }
};