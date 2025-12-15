#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Min-heap priority queue to pick the node with the smallest distance
    // Stores {distance, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Initialize distances with "infinity"
    vector<int> dist(V, 1e9);

    // Distance to source itself is 0
    dist[S] = 0;

    // Start with source node
    pq.push({0, S});

    // Process nodes until the queue is empty
    while (!pq.empty())
    {
        int dis = pq.top().first;   // Current shortest distance
        int node = pq.top().second; // Current node being processed
        pq.pop();

        // Traverse all neighbors of current node
        for (auto it : adj[node])
        {
            int adjNode = it[0];    // Neighbor vertex
            int edgeWeight = it[1]; // Weight of edge from node -> adjNode

            // Relaxation: If current path offers shorter distance, update it
            if (dis + edgeWeight < dist[adjNode])
            {
                dist[adjNode] = dis + edgeWeight;  // Update shortest distance
                pq.push({dist[adjNode], adjNode}); // Add neighbor to priority queue
            }
        }
    }

    return dist;
}
