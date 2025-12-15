#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int> > &graph)
    {
        int v = graph.size();

        // Reverese the edges
        vector<vector<int> > adjRev(v);
        for (int i = 0; i < v; i++)
        {
            for (auto it : graph[i])
                adjRev[it].push_back(i);
        }

        vector<int> indegree(v, 0);
        for (int i = 0; i < v; i++)
        {
            for (auto it : adjRev[i])
                indegree[it]++;
        }

        queue<int> q;
        for (int i = 0; i < v; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> safe;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            safe.push_back(node);

            for (auto it : adjRev[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        sort(safe.begin(), safe.end());
        return safe;
    }
};

int main(){
    return 0;
}