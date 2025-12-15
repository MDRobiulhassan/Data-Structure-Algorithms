#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        // Step 1️⃣: Build the adjacency list
        // Each entry 'adj[u]' contains pairs {v, price} for flights u -> v
        vector<vector<pair<int, int>>> adj(n);
        for (auto it : flights)
        {
            int f = it[0]; // from
            int t = it[1]; // to
            int p = it[2]; // price
            adj[f].push_back({t, p});
        }

        // Step 2️⃣: Queue will store {stopsUsed, {node, totalCost}}
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}}); // start with source city, 0 cost, and 0 stops

        // Step 3️⃣: Distance array to store the minimum cost to reach each node
        vector<int> dist(n, 1e9);
        dist[src] = 0; // cost to reach source = 0

        // Step 4️⃣: BFS-like traversal (modified for cost and stops)
        while (!q.empty())
        {
            auto it = q.front(); // get the current state
            q.pop();

            int stops = it.first;       // number of stops taken so far
            int node = it.second.first; // current city
            int dis = it.second.second; // total cost so far

            // If we’ve already used more than k stops, skip this path
            if (stops > k)
                continue;

            // Step 5️⃣: Explore all neighboring cities from 'node'
            for (auto iter : adj[node])
            {
                int adjNode = iter.first; // next city
                int edW = iter.second;    // flight price

                // If taking this flight results in a cheaper cost to reach adjNode,
                // AND we still have stops remaining
                if (dis + edW < dist[adjNode] && stops <= k)
                {
                    dist[adjNode] = dis + edW;                     // update cheapest cost to reach this city
                    q.push({stops + 1, {adjNode, dist[adjNode]}}); // explore further from here
                }
            }
        }

        // Step 6️⃣: Return result — if destination unreachable, return -1
        if (dist[dst] == 1e9)
            return -1;

        return dist[dst]; // otherwise return the minimum cost found
    }
};
