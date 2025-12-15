#include <bits/stdc++.h>
using namespace std;

vector<int> dijsktras(int V, vector<vector<int>> adj[], int src)
{
    // Set to store pairs of (distance, node)
    // Always keeps the node with the smallest distance at the front
    set<pair<int, int>> st;

    // Distance array initialized to infinity (1e9)
    vector<int> dist(V, 1e9);

    // Distance to source node is always 0
    dist[src] = 0;

    // Insert the source node with distance 0
    st.insert({0, src});

    // Loop until all nodes are processed
    while (!st.empty())
    {
        // Get the node with the smallest distance
        auto it = *st.begin();
        int node = it.second;
        int dis = it.first;

        // Remove it from the set as we are now processing it
        st.erase(it);

        // Explore all adjacent nodes of the current node
        for (auto it : adj[node])
        {
            int adjNode = it[0];    // Neighbor node
            int edgeWeight = it[1]; // Weight of the edge

            // Check if the new distance is shorter
            if (dis + edgeWeight < dist[adjNode])
            {
                // Update the distance with the smaller value
                dist[adjNode] = dis + edgeWeight;

                // Insert the updated distance for this node into the set
                st.insert({dist[adjNode], adjNode});
            }
        }
    }

    // Return the final distance array
    return dist;
}
