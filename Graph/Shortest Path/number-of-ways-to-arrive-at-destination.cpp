#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define vs vector<string>
#define pb push_back
#define tc while (t--)
#define l1n for (int i = 0; i < n; i++)

const int MOD = 1e9 + 7;

class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<vector<pair<ll, ll>>> adj(n);
        for (auto it : roads)
        {
            ll u = it[0];
            ll v = it[1];
            ll t = it[2];

            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        vector<ll> dist(n, 1e12);
        dist[0] = 0;
        vector<ll> ways(n, 0);
        ways[0] = 1;

        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>,
                       greater<pair<ll, ll>>>
            pq;
        pq.push({0, 0});

        while (!pq.empty())
        {
            auto it = pq.top();
            ll node = it.second;
            ll dis = it.first;
            pq.pop();

            for (auto iter : adj[node])
            {
                ll adjNode = iter.first;
                ll time = iter.second;

                if (dis + time < dist[adjNode])
                {
                    dist[adjNode] = dis + time;
                    pq.push({dist[adjNode], adjNode});
                    ways[adjNode] = ways[node]; // first time reaching that node
                }

                // already reached that node with same shortest distance
                else if (dis + time == dist[adjNode])
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
            }
        }

        return ways[n - 1] % MOD;
    }
};