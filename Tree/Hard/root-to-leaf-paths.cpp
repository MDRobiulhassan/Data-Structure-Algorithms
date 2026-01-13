#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    void traverse(Node *node, vector<vector<int>> &path, vector<int> &temp)
    {

        if (node == NULL)
            return;

        temp.push_back(node->data);

        if (!node->left && !node->right)
            path.push_back(temp);
        else
        {
            traverse(node->left, path, temp);
            traverse(node->right, path, temp);
        }

        temp.pop_back();
    }

    vector<vector<int>> Paths(Node *root)
    {
        vector<vector<int>> path;
        vector<int> temp;
        traverse(root, path, temp);
        return path;
    }
};