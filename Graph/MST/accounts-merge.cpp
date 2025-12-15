#include <bits/stdc++.h>
using namespace std;

// Disjoint Set (Union-Find) implementation
class DisjointSet
{
    vector<int> rank, parent, size;

public:
    // Constructor to initialize DSU
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        // Initialize every node
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    // Function to find ultimate parent with path compression
    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        parent[node] = findUPar(parent[node]);
        return parent[node];
    }

    // Function to perform union by rank
    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    // Function to perform union by size
    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int n = accounts.size();

        // Initialize Disjoint Set for 'n' accounts
        DisjointSet ds(n);

        unordered_map<string, int> mailMap;
        // Maps email -> account index. Used to connect accounts with same emails.

        // Step 1: Union accounts that share the same email
        for (int i = 0; i < n; i++)
        {
            // Loop through all emails of account i
            for (int j = 1; j < accounts[i].size(); j++)
            {
                string mail = accounts[i][j];
                if (mailMap.find(mail) == mailMap.end())
                    mailMap[mail] = i; // First time seeing this email
                else
                    ds.unionBySize(i, mailMap[mail]); // Merge accounts sharing this email
            }
        }

        // Step 2: Collect emails under their parent account
        unordered_map<int, set<string>> mergedMail;
        // Using 'set' ensures emails are unique and sorted
        for (auto it : mailMap)
        {
            string mail = it.first;
            int parent = ds.findUPar(it.second); // Find representative parent account
            mergedMail[parent].insert(mail);     // Add email to parent account
        }

        // Step 3: Build the final answer
        vector<vector<string>> ans;
        for (auto it : mergedMail)
        {
            int idx = it.first;
            vector<string> temp;
            temp.push_back(accounts[idx][0]); // Add account name at the start
            for (auto &mail : it.second)
            { // Add all emails for this account
                temp.push_back(mail);
            }
            ans.push_back(temp); // Append merged account to answer
        }

        return ans;
    }
};
