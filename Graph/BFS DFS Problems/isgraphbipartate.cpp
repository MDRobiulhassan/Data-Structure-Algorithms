#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool dfs(int node, int col, vector<int> &color,
             vector<vector<int> > &graph)
    {
        color[node] = col;

        // commented due to old compiler version
        //  for (auto it : graph[node])
        //  {
        //      if (color[it] == -1)
        //      {
        //          if (dfs(it, !col, color, graph) == false)
        //              return false;
        //      }
        //      else if (color[it] == col)
        //          return false;
        //  }

        for (int i = 0; i < graph[node].size(); i++)
        {
            int neighbor = graph[node][i];

            if (color[neighbor] == -1)
            {
                if (dfs(neighbor, 1 - col, color, graph) == false)
                {
                    return false;
                }
            }
            else if (color[neighbor] == col)
            {
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int> > &graph)
    {
        int v = graph.size();
        vector<int> color(v, -1);

        for (int i = 0; i < v; i++)
        {
            if (color[i] == -1)
            {
                if (dfs(i, 0, color, graph) == false)
                    return false;
            }
        }
        return true;
    }
};