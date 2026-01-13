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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (root == NULL)
            return {};

        vector<vector<int>> ans;

        queue<TreeNode *> q;
        q.push(root);

        bool leftToright = true;
        while (!q.empty())
        {
            int sz = q.size();
            vector<int> level(sz);
            for (int i = 0; i < sz; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                int ind = (leftToright) ? i : sz - 1 - i;
                level[ind] = node->val;

                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
            }

            leftToright = !leftToright;
            ans.push_back(level);
        }

        return ans;
    }
};