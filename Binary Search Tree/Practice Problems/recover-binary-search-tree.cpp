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
    vector<TreeNode *> in;

    void inorder(TreeNode *root)
    {
        if (!root)
            return;

        inorder(root->left);
        in.push_back(root);
        inorder(root->right);
    }

    void recoverTree(TreeNode *root)
    {
        inorder(root);

        TreeNode *node1 = NULL, *node2 = NULL;
        for (int i = 0; i < in.size() - 1; i++)
        {
            if (in[i]->val > in[i + 1]->val)
            {
                if (!node1)
                {
                    node1 = in[i];
                }
                node2 = in[i + 1];
            }
        }

        swap(node1->val, node2->val);
    }
};