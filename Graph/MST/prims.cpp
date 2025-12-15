#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> &edges)
    {

        vector<vector<pair<int, int>>> adj(V);

        // Convert edges list to adjacency list
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        // Min-heap: stores {weight, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, 0}); // Start from node 0 with 0 cost

        vector<int> vis(V, 0); // To mark visited nodes
        int sum = 0;           // MST total weight

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            int wt = it.first;
            int node = it.second;

            // If already visited, skip
            if (vis[node])
                continue;

            vis[node] = 1; // Mark visited

            sum += wt; // Add weight to MST

            // Push all adjacent edges to PQ
            for (auto iter : adj[node])
            {
                int adjNode = iter.first;
                int edw = iter.second;

                if (!vis[adjNode])
                    pq.push({edw, adjNode});
            }
        }

        return sum; 
    }
};
