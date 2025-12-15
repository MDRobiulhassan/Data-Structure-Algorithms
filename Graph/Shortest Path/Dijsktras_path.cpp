#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
    {
        // Step 1️⃣: Build adjacency list from edge list
        // Each element of adj[u] contains pairs (v, w) → meaning there is an edge from u to v with weight w.
        vector<pair<int, int>> adj[V];
        for (auto it : edges)
        {
            int u = it[0]; // starting node of edge
            int v = it[1]; // ending node of edge
            int w = it[2]; // weight of edge

            // Since the graph is undirected, we push both directions
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // Step 2️⃣: Initialize distance array with a large value (infinity)
        vector<int> dist(V, 1e9);
        dist[src] = 0; // distance from source to itself = 0

        // Step 3️⃣: Parent array to help reconstruct the path later
        vector<int> parent(V);
        for (int i = 0; i < V; i++)
        {
            parent[i] = i; // initially, each node is its own parent
        }

        // Step 4️⃣: Min-heap (priority queue) for {distance, node}
        // This ensures the node with the smallest distance is always processed first.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Type, Container, Comparator
        pq.push({0, src});                                                                  // start from the source node

        // Step 5️⃣: Dijkstra's main loop
        while (!pq.empty())
        {
            auto it = pq.top(); // get node with smallest distance
            int dis = it.first; // current shortest known distance
            int node = it.second;
            pq.pop();

            // Traverse all adjacent nodes of the current node
            for (auto edge : adj[node])
            {
                int edW = edge.second;    // edge weight
                int adjNode = edge.first; // connected node

                // Relaxation step:
                // If we found a shorter path to adjNode through this node
                if (dis + edW < dist[adjNode])
                {
                    dist[adjNode] = dis + edW;         // update shortest distance
                    pq.push({dist[adjNode], adjNode}); // push updated distance to queue
                    parent[adjNode] = node;            // track path
                }
            }
        }

        // Step 6️⃣: If the destination (V-1) is unreachable, return -1
        if (dist[V - 1] == 1e9)
            return {-1};

        // Step 7️⃣: Reconstruct the shortest path from src → V-1
        vector<int> path;
        int node = V - 1;
        while (parent[node] != node)
        {
            path.push_back(node);
            node = parent[node];
        }

        // Add the source node to path
        path.push_back(src);

        // Reverse it since we built it backward (destination → source)
        reverse(path.begin(), path.end());

        // Step 8️⃣: Return the path vector
        return path;
    }
};
