#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
public:
    vector<int> topView(Node *root)
    {
        // Map to store the first node encountered at each vertical line
        // key   -> horizontal distance (line)
        // value -> node->data
        map<int, int> m;

        // Queue for level order traversal
        // Stores pair of (Node*, horizontal distance)
        queue<pair<Node *, int>> q;

        // Push root node with horizontal distance 0
        q.push({root, 0});

        // BFS traversal
        while (!q.empty())
        {
            // Get front element of queue
            auto it = q.front();
            q.pop();

            Node *node = it.first; // current node
            int line = it.second;  // horizontal distance

            // If this vertical line is encountered first time,
            // store the node's data (top view logic)
            if (m.find(line) == m.end())
                m[line] = node->data;

            // Move to left child with horizontal distance -1
            if (node->left)
                q.push({node->left, line - 1});

            // Move to right child with horizontal distance +1
            if (node->right)
                q.push({node->right, line + 1});
        }

        // Store result from map (sorted by horizontal distance)
        vector<int> ans;
        for (auto it : m)
        {
            ans.push_back(it.second);
        }

        return ans;
    }
};
