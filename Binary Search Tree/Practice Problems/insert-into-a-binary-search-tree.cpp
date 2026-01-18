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
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (!root)
            return new TreeNode(val);

        TreeNode *newNode = new TreeNode(val);
        TreeNode *node = root, *lastNode = NULL;

        while (node)
        {
            lastNode = node;
            if (val > node->val)
            {
                node = node->right;
            }
            else
            {
                node = node->left;
            }
        }

        if (val > lastNode->val)
            lastNode->right = newNode;
        else
            lastNode->left = newNode;

        return root;
    }
};