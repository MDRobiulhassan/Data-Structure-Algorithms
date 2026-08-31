#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Check if it's safe to color 'node' with color 'col'
    bool isSafe(int node, int col, vector<int> &color,
                vector<vector<int>> &adj)
    {

        // Check all adjacent nodes
        for (int neigh : adj[node])
        {
            // If any neighbor already has the same color → not safe
            if (color[neigh] == col)
                return false;
        }
        return true; // Safe to use this color
    }

    // Recursive function to try coloring each node
    bool solve(int node, int v, int m,
               vector<int> &color,
               vector<vector<int>> &adj)
    {

        // Base case:
        // If all vertices are colored successfully
        if (node == v)
            return true;

        // Try all colors from 1 to m
        for (int col = 1; col <= m; col++)
        {

            // Check if current color is safe for this node
            if (isSafe(node, col, color, adj))
            {

                // Choose the color
                color[node] = col;

                // Recurse to color the next node
                if (solve(node + 1, v, m, color, adj))
                    return true;

                // Backtrack:
                // If coloring next nodes fails, remove color
                color[node] = 0;
            }
        }

        // No color worked for this node
        return false;
    }

    bool graphColoring(int v, vector<vector<int>> &edges, int m)
    {

        // Convert edge list to adjacency list
        vector<vector<int>> adj(v);
        for (auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // color[i] = color assigned to vertex i (0 = uncolored)
        vector<int> color(v, 0);

        // Start coloring from node 0
        return solve(0, v, m, color, adj);
    }
};
