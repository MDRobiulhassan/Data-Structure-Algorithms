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
    vector<int> leftView(Node *root)
    {
        if (!root)
            return {};

        vector<int> ans;
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int sz = q.size();

            for (int i = 0; i < sz; i++)
            {
                auto node = q.front();
                q.pop();

                if (i == 0)
                    ans.push_back(node->data);

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }

        return ans;
    }
};