#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int timer = 1; // Global timer to assign discovery times

    // DFS function for Tarjan's Bridge Finding Algorithm
    void dfs(int node, int parent,
             vector<int> &vis,
             vector<vector<int>> &adj,
             vector<vector<int>> &bridges,
             vector<int> &tin,
             vector<int> &low)
    {

        vis[node] = 1;                   // mark node as visited
        tin[node] = low[node] = timer++; // set discovery & low time

        // traverse all adjacent nodes
        for (auto it : adj[node])
        {

            // skip the edge leading back to parent
            if (it == parent)
                continue;

            // if adjacent node is not visited
            if (!vis[it])
            {

                // DFS call for child
                dfs(it, node, vis, adj, bridges, tin, low);

                // update low time after returning from DFS
                low[node] = min(low[node], low[it]);

                // bridge condition:
                // if child cannot reach an ancestor of node
                if (low[it] > tin[node])
                {
                    bridges.push_back({node, it});
                }
            }
            else
            {
                // back edge case
                // update low time using discovery time of visited node
                low[node] = min(low[node], tin[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>> &connections)
    {

        vector<vector<int>> adj(n);
        for (auto &it : connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n, 0); // visited array
        vector<int> tin(n);    // discovery time
        vector<int> low(n);    // low-link values
        vector<vector<int>> bridges;

        // run DFS for all components (important for disconnected graphs)
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, -1, vis, adj, bridges, tin, low);
            }
        }

        return bridges; // return all critical connections
    }
};
