#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(int i, vector<int> &vis, vector<vector<int> > &adj)
    {
        vis[i] = 1;

        // for (auto it : adj[i])
        // {
        //     if (!vis[it])
        //     {
        //         dfs(it, vis, adj);
        //     }
        // }

        for (int j = 0; j < adj[i].size(); j++)
        {
            int neighbor = adj[i][j];
            if (!vis[neighbor])
            {
                dfs(neighbor, vis, adj);
            }
        }
    }

    int findCircleNum(vector<vector<int> > &isConnected)
    {
        int v = isConnected.size();
        vector<vector<int> > adj(v);

        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (isConnected[i][j] == 1 && i != j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int count = 0;
        vector<int> vis(v, 0);
        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                count++;
                dfs(i, vis, adj);
            }
        }

        return count;
    }
};