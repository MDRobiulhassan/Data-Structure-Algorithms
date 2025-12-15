#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> topoSort(vector<vector<int>> &adj, vector<bool> &present)
    {
        vector<int> indegree(26, 0);
        for (int i = 0; i < 26; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < 26; i++)
        {
            if (present[i] && indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        return topo;
    }

    string findOrder(vector<string> &words)
    {
        vector<vector<int>> adj(26);
        vector<bool> present(26, false);

        // Mark which characters actually appear
        for (auto &w : words)
        {
            for (char c : w)
                present[c - 'a'] = true;
        }

        // Build graph
        for (int i = 0; i < words.size() - 1; i++)
        {
            string s1 = words[i], s2 = words[i + 1];

            // invalid case: prefix issue
            if (s1.size() > s2.size() && s1.substr(0, s2.size()) == s2)
            {
                return "";
            }

            int len = min(s1.size(), s2.size());
            for (int j = 0; j < len; j++)
            {
                if (s1[j] != s2[j])
                {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }

        vector<int> topo = topoSort(adj, present);

        // check for cycles
        int countChars = 0;
        for (bool p : present)
            if (p)
                countChars++;
        if (topo.size() < countChars)
            return "";

        // Build answer
        string ans = "";
        for (auto it : topo)
        {
            if (present[it])
                ans += char(it + 'a');
        }

        return ans;
    }
};
