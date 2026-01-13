#include <iostream>
#include <vector>

using namespace std;

// Node structure for the binary tree
struct Node
{
    int data;
    Node *left;
    Node *right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    // Checks whether a node is a leaf node
    // A leaf node has no left and no right child
    bool isLeaf(Node *node)
    {
        return !node->left && !node->right;
    }

    // Adds the left boundary of the tree (excluding leaf nodes)
    void addLeftBoundary(Node *root, vector<int> &res)
    {
        // Start from the left child of root
        Node *node = root->left;

        // Traverse down until we reach NULL
        while (node)
        {
            // Add only non-leaf nodes
            if (!isLeaf(node))
                res.push_back(node->data);

            // Prefer moving to the left child
            if (node->left)
                node = node->left;
            // If left child doesn't exist, move right
            else
                node = node->right;
        }
    }

    // Adds the right boundary of the tree (excluding leaf nodes)
    void addRightBoundary(Node *root, vector<int> &res)
    {
        // Start from the right child of root
        Node *node = root->right;
        vector<int> temp; // Temporary storage for reverse order

        // Traverse down the right boundary
        while (node)
        {
            // Add only non-leaf nodes
            if (!isLeaf(node))
                temp.push_back(node->data);

            // Prefer moving to the right child
            if (node->right)
                node = node->right;
            // If right child doesn't exist, move left
            else
                node = node->left;
        }

        // Right boundary must be added in bottom-up order
        for (int i = temp.size() - 1; i >= 0; i--)
            res.push_back(temp[i]);
    }

    // Adds all leaf nodes using DFS (left to right)
    void addLeaves(Node *node, vector<int> &res)
    {
        // If current node is a leaf, add it
        if (isLeaf(node))
        {
            res.push_back(node->data);
            return;
        }

        // Recur on left subtree
        if (node->left)
            addLeaves(node->left, res);

        // Recur on right subtree
        if (node->right)
            addLeaves(node->right, res);
    }

    // Main function to perform boundary traversal
    vector<int> boundaryTraversal(Node *root)
    {
        // If tree is empty, return empty result
        if (!root)
            return {};

        vector<int> res;

        // Add root only if it's not a leaf
        // (to avoid duplication when tree has only one node)
        if (!isLeaf(root))
            res.push_back(root->data);

        // Add left boundary
        addLeftBoundary(root, res);

        // Add all leaf nodes
        addLeaves(root, res);

        // Add right boundary
        addRightBoundary(root, res);

        return res;
    }
};
