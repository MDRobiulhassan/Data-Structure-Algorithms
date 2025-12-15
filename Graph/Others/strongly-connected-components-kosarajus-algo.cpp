#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void dfs(int node, vector<int> &vis, stack<int> &st, vector<vector<int>> &adj)
    {
        vis[node] = 1;

        for (auto it : adj[node])
        {
            if (!vis[it])
                dfs(it, vis, st, adj);
        }

        st.push(node);
    }

    void dfs(int node, vector<int> &vis, vector<vector<int>> &adjT)
    {
        vis[node] = 1;

        for (auto it : adjT[node])
        {
            if (!vis[it])
                dfs(it, vis, adjT);
        }
    }

public:
    int kosaraju(vector<vector<int>> &adj)
    {
        int n = adj.size();

        vector<int> vis(n, 0);
        stack<int> st;

        // step 1 : sort base on finishing time
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, st, adj);
            }
        }

        // step 2 : reverse the graph
        vector<vector<int>> adjT(n);
        for (int i = 0; i < n; i++)
        {
            vis[i] = 0;
            for (auto it : adj[i])
            {
                adjT[it].push_back(i);
            }
        }

        // step 3 : do another dfs to count scc
        int scc = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            if (!vis[node])
            {
                scc++;
                dfs(node, vis, adjT);
            }
        }

        return scc;
    }
};