#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // Base case:
        // If we reach NULL, or we find p, or we find q
        // return that node upward as a signal
        if (root == NULL || root == p || root == q)
            return root;

        // Recur for left subtree
        // This will return:
        // - NULL (found nothing)
        // - p or q (found one target)
        // - LCA (already found answer below)
        TreeNode *left = lowestCommonAncestor(root->left, p, q);

        // Recur for right subtree
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        // If left subtree found nothing,
        // whatever is found must be in the right subtree
        if (left == NULL)
            return right;

        // If right subtree found nothing,
        // whatever is found must be in the left subtree
        else if (right == NULL)
            return left;

        // If both left and right are NOT NULL,
        // p and q were found in different subtrees
        // So current node is the LCA
        else
            return root;
    }
};
