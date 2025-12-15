#include <bits/stdc++.h>
using namespace std;

// This class finds articulation points in a graph using Tarjan's algorithm.
// Articulation points are vertices whose removal increases the number of connected components.

class Solution
{
private:
    int timer = 0;

    // DFS helper function
    void dfs(int node, int parent, vector<int> &tin, vector<int> &low,
             vector<int> adj[], vector<int> &mark, vector<int> &vis)
    {
        vis[node] = 1;                   // mark node as visited
        tin[node] = low[node] = timer++; // initialize discovery and low times
        int child = 0;

        for (auto it : adj[node])
        {
            if (it == parent)
                continue; // skip the parent

            if (!vis[it])
            { // if neighbor is not visited
                dfs(it, node, tin, low, adj, mark, vis);
                low[node] = min(low[node], low[it]); // update low time

                // If not root and low[it] >= tin[node], node is an articulation point
                if (low[it] >= tin[node] && parent != -1)
                    mark[node] = 1;

                child++;
            }
            else
            { // if neighbor is already visited (back edge)
                low[node] = min(low[node], tin[it]);
            }
        }

        // Root node is an articulation point if it has more than one child
        if (parent == -1 && child > 1)
            mark[node] = 1;
    }

public:
    vector<int> articulationPoints(int n, vector<int> adj[])
    {
        vector<int> tin(n), low(n), vis(n, 0), mark(n, 0);

        // Run DFS from unvisited nodes to cover disconnected graphs
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
                dfs(i, -1, tin, low, adj, mark, vis);
        }

        // Collect articulation points
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (mark[i])
                ans.push_back(i);
        }

        // If no articulation points found, return -1
        if (ans.size() == 0)
            return {-1};

        return ans;
    }
};
