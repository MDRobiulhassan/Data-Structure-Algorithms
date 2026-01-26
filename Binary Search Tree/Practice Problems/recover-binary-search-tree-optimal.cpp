#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution
{
public:
    TreeNode *prev, *first, *middle, *last;

    void inorder(TreeNode *root)
    {
        if (!root)
            return;

        // Visit left subtree
        inorder(root->left);

        // Detect a violation of BST property
        if (prev && root->val < prev->val)
        {
            if (!first)
            {
                // First violation: prev is the first node, current is middle
                first = prev;
                middle = root;
            }
            else
            {
                // Second violation: current node is the last node
                last = root;
            }
        }

        // Update prev pointer
        prev = root;

        // Visit right subtree
        inorder(root->right);
    }

    void recoverTree(TreeNode *root)
    {
        // Initialize pointers
        first = middle = last = nullptr;
        prev = new TreeNode(INT_MIN); // ensures first comparison works

        // Perform inorder traversal to find swapped nodes
        inorder(root);

        // Swap the values to fix BST
        // Case 1: Non-adjacent swap (first and last)
        if (first && last)
            swap(first->val, last->val);
        // Case 2: Adjacent swap (first and middle)
        else if (first && middle)
            swap(first->val, middle->val);
    }
};
