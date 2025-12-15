#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void fun(int n, vector<vector<int> > &adj, vector<int> &ls, vector<int> &vis, int node)
    {
        vis[node] = 1;
        ls.push_back(node);

        // for (auto it : adj[node])
        // {
        //     if (!vis[it])
        //         fun(n, adj, ls, vis, it);
        // }
        for (int i = 0; i < adj[node].size(); i++)
        {
            int it = adj[node][i];
            if (!vis[it])
                fun(n, adj, ls, vis, it);
        }
    }

    vector<int> dfs(vector<vector<int> > &adj)
    {
        int n = adj.size();
        vector<int> vis(n, 0);
        vector<int> ls;

        fun(n, adj, ls, vis, 0);
        return ls;
    }
};