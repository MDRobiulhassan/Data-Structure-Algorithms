#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    // Finds the rightmost (maximum) node in a subtree
    TreeNode *findLastRight(TreeNode *root)
    {
        while (root->right)
            root = root->right;
        return root;
    }

    // Handles deletion of a node and returns the new subtree root
    TreeNode *helper(TreeNode *root)
    {
        // Case 1: no left child → replace node with right child
        if (!root->left)
            return root->right;

        // Case 2: no right child → replace node with left child
        if (!root->right)
            return root->left;

        // Case 3: node has both left and right children
        // Save the right subtree
        TreeNode *rightChild = root->right;

        // Find the rightmost node of the left subtree
        TreeNode *lastRight = findLastRight(root->left);

        // Attach original right subtree to it
        lastRight->right = rightChild;

        // Return left subtree as the new root
        return root->left;
    }

    TreeNode *deleteNode(TreeNode *root, int key)
    {
        // If tree is empty
        if (!root)
            return root;

        // Special case: root itself is the node to delete
        if (root->val == key)
            return helper(root);

        // Traverse the tree to find the node to delete
        TreeNode *cur = root;
        while (cur)
        {
            // Go left if key is smaller
            if (key < cur->val)
            {
                // If left child is the node to delete
                if (cur->left && cur->left->val == key)
                {
                    cur->left = helper(cur->left); // delete and reattach
                    break;
                }
                else
                {
                    cur = cur->left; // keep searching
                }
            }
            // Go right if key is greater or equal
            else
            {
                // If right child is the node to delete
                if (cur->right && cur->right->val == key)
                {
                    cur->right = helper(cur->right); // delete and reattach
                    break;
                }
                else
                {
                    cur = cur->right; // keep searching
                }
            }
        }

        return root;
    }
};
