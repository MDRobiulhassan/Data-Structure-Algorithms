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
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> postorder;
        stack<TreeNode *> st;
        TreeNode *cur = root;
        TreeNode *lastVisited = NULL;

        while (cur || !st.empty())
        {
            if (cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            else
            {
                TreeNode *node = st.top();

                if (node->right && lastVisited != node->right)
                {
                    cur = node->right;
                }
                else
                {
                    postorder.push_back(node->val);
                    lastVisited = node;
                    st.pop();
                }
            }
        }

        return postorder;
    }
};
