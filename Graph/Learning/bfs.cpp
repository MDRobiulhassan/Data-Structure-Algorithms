#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> bfs(vector<vector<int> > &adj)
    {
        int n = adj.size();
        int vis[n] = {0};
        vis[0] = 1;
        queue<int> q;
        q.push(0);
        vector<int> bfs;

        while (!q.empty())
        {
            int node = q.front();
            bfs.push_back(node);
            q.pop();

            // for (auto it : adj[node])
            // {
            //     if (!vis[it])
            //     {
            //         vis[it] = 1;
            //         q.push(it);
            //     }
            // }
            for (int i = 0; i < (int)adj[node].size(); i++)
            {
                int it = adj[node][i];
                if (!vis[it])
                {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};