#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isCyclic(int V, vector<vector<int> > &edges)
    {
        vector<vector<int> > adj(V);

        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
        }

        vector<int> indegree(V);
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
                indegree[it]++;
        }

        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        int size = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            size++;

            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        return (size != V);
    }
};