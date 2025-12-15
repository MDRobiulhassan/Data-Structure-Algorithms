#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool detect(int src, vector<int> &vis, vector<vector<int> > &edges)
    {
        vis[src] = 1;
        queue<pair<int, int> > q;

        q.push({src, -1});

        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            // working part,commented due to compiler version
            // for (auto adjacentNode : edges[node])
            // {
            //     if (!vis[adjacentNode])
            //     {
            //         vis[adjacentNode] = 1;
            //         q.push({adjacentNode, node});
            //     }
            //     else if (parent != adjacentNode)
            //         return true;
            // }
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int> > &edges)
    {
        vector<vector<int> > adj(V);

        // working part,commented due to compiler version
        //  for (auto &e : edges)
        //  {
        //      int u = e[0];
        //      int v = e[1];
        //      adj[u].push_back(v);
        //      adj[v].push_back(u);
        //  }
        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (detect(i, vis, adj))
                    return true;
            }
        }

        return false;
    }
};