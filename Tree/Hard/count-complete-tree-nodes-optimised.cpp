#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    // Main function to count nodes
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0; // Base case: empty tree has 0 nodes

        // Get the height of the leftmost path
        int left = findLeftHeight(root);

        // Get the height of the rightmost path
        int right = findRightHeight(root);

        // If left and right heights are equal, tree is perfect
        // Number of nodes in perfect binary tree = 2^height - 1
        if (left == right)
            return (1 << left) - 1;

        // Otherwise, recursively count nodes in left and right subtrees
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    // Function to find height along the leftmost path
    int findLeftHeight(TreeNode *node)
    {
        int height = 0;
        while (node)
        {
            height++;
            node = node->left;
        }
        return height;
    }

    // Function to find height along the rightmost path
    int findRightHeight(TreeNode *node)
    {
        int height = 0;
        while (node)
        {
            height++;
            node = node->right;
        }
        return height;
    }
};
