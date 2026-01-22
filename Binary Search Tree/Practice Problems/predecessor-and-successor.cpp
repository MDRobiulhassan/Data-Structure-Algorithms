#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    Node *findMax(Node *root)
    {
        while (root->right)
            root = root->right;
        return root;
    }

    Node *findMin(Node *root)
    {
        while (root->left)
            root = root->left;
        return root;
    }

    vector<Node *> findPreSuc(Node *root, int key)
    {
        Node *pre = nullptr;
        Node *succ = nullptr;
        Node *node = root;

        // Step 1: Traverse to find the node
        while (node && node->data != key)
        {
            if (key < node->data)
            {
                succ = node;
                node = node->left;
            }
            else
            {
                pre = node;
                node = node->right;
            }
        }

        // Step 2: If node exists, check its subtrees
        if (node)
        {
            if (node->left)
                pre = findMax(node->left);
            if (node->right)
                succ = findMin(node->right);
        }

        return {pre, succ};
    }
};
