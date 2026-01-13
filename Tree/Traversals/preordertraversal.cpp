#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    // TreeNode() : val(0), left(nullptr), right(nullptr) {}
    // TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    // TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
    //                                                    right(right) {}
};
class Solution
{
public:
    vector<int> preorder(TreeNode *node)
    {
        vector<int> ans;

        if (node == NULL)
            return {};
        ans.push_back(node->val);

        vector<int> l = preorder(node->left);
        vector<int> r = preorder(node->right);

        ans.insert(ans.end(), l.begin(), l.end());
        ans.insert(ans.end(), r.begin(), r.end());

        return ans;
    }

    vector<int> preorderTraversal(TreeNode *root) { return preorder(root); }
};