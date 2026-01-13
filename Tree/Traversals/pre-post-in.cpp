#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    vector<int> pre, post, in;
    void traversal(TreeNode *root)
    {
        stack<pair<TreeNode *, int>> st;
        st.push({root, 1});

        while (!st.empty())
        {
            auto it = st.top();
            st.pop();

            if (it.second == 1)
            {
                pre.push_back(it.first->val);
                it.second++;
                st.push(it);

                if (it.first->left)
                {
                    st.push({it.first->left, 1});
                }
            }
            else if (it.second == 2)
            {
                in.push_back(it.first->val);
                it.second++;
                st.push(it);

                if (it.first->right)
                {
                    st.push({it.first->right, 1});
                }
            }
            else
            {
                post.push_back(it.first->val);
            }
        }
    }

    void preorder()
    {
        for (auto it : pre)
            cout << it << " ";
        cout << '\n';
    }

    void inorder()
    {
        for (auto it : in)
            cout << it << " ";
        cout << '\n';
    }

    void postorder()
    {
        for (auto it : post)
            cout << it << " ";
        cout << '\n';
    }
};

int main()
{
    queue<TreeNode *> q;
    TreeNode *root = new TreeNode(1);
    q.push(root);

    int i = 2;
    while (i <= 10)
    {
        TreeNode *cur = q.front();
        q.pop();

        cur->left = new TreeNode(i++);
        q.push(cur->left);

        if (i <= 10)
        {
            cur->right = new TreeNode(i++);
            q.push(cur->right);
        }
    }

    Solution sol;
    sol.traversal(root);
    sol.preorder();
    sol.inorder();
    sol.postorder();
}