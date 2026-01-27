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
    int ans = 0; // stores size of the largest BST found so far

    // This structure stores information about each subtree
    struct Info
    {
        bool isBST; // whether the subtree is a BST
        int size;   // size of the subtree if it's a BST
        int minVal; // minimum value in the subtree
        int maxVal; // maximum value in the subtree
    };

    // Postorder traversal to compute Info for each node
    Info solve(Node *root)
    {

        // Base case: empty tree is a BST of size 0
        if (!root)
        {
            return {true, 0, INT_MAX, INT_MIN};
        }

        // Recursively solve left and right subtrees
        Info left = solve(root->left);
        Info right = solve(root->right);

        Info cur;

        // Check BST property:
        // 1. Left subtree must be BST
        // 2. Right subtree must be BST
        // 3. Current node value must be greater than max of left subtree
        // 4. Current node value must be less than min of right subtree
        if (left.isBST && right.isBST &&
            root->data > left.maxVal &&
            root->data < right.minVal)
        {

            // Current subtree is a BST
            cur.isBST = true;

            // Size of BST = left + right + current node
            cur.size = left.size + right.size + 1;

            // Minimum value in this subtree
            cur.minVal = min(root->data, left.minVal);

            // Maximum value in this subtree
            cur.maxVal = max(root->data, right.maxVal);

            // Update global maximum BST size
            ans = max(ans, cur.size);
        }
        else
        {
            // Current subtree is NOT a BST
            cur.isBST = false;
            cur.size = 0;
        }

        // Return information about current subtree to parent
        return cur;
    }

    // Driver function
    int largestBst(Node *root)
    {
        solve(root); // compute info for entire tree
        return ans;  // return largest BST size
    }
};
