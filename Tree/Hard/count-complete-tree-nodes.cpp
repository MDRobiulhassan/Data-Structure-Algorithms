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
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;

        int left = countNodes(root->left);
        int right = countNodes(root->right);

        return left + right + 1;
    }
};