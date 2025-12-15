#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool dfsCheck(int node, vector<int> &vis, vector<int> &pathVis,
                  vector<vector<int> > &adj, vector<int> &ans)
    {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                if (dfsCheck(it, vis, pathVis, adj, ans))
                    return true;
            }
            else if (pathVis[it])
                return true;
        }

        pathVis[node] = 0;
        ans.push_back(node);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int> > &prerequisites)
    {
        vector<vector<int> > adj(numCourses);

        for (auto &pre : prerequisites)
        {
            int course = pre[0];
            int prereq = pre[1];
            adj[prereq].push_back(course);
        }

        vector<int> vis(numCourses);
        vector<int> pathVis(numCourses);
        vector<int> ans;

        for (int i = 0; i < numCourses; i++)
        {
            if (!vis[i])
            {
                if (dfsCheck(i, vis, pathVis, adj, ans))
                    return {};
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};