#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
    {
        vector<int> dist(V, 1e8);
        dist[src] = 0;

        for (int i = 0; i < V - 1; i++)
        {
            for (auto it : edges)
            {
                int u = it[0];
                int v = it[1];
                int wt = it[2];

                if (dist[u] + wt < dist[v] && dist[u] != 1e8)
                {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        // negative cycle
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if (dist[u] + wt < dist[v] && dist[u] != 1e8)
            {
                return {-1};
            }
        }

        return dist;
    }
};
