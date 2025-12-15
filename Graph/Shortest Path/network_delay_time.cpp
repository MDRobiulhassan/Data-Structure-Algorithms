#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {

        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto it : times)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v, w});
        }

        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, k});

        int last = -1;
        while (!pq.empty())
        {
            auto it = pq.top();
            int dis = it.first;
            int node = it.second;
            last = node;
            pq.pop();

            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int time = it.second;

                if (dis + time < dist[adjNode])
                {
                    dist[adjNode] = dis + time;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] == 1e9)
                return -1;
            else
                ans = max(ans, dist[i]);
        }
        return ans;
    }
};