#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void morrisInorder(TreeNode *root)
{
    TreeNode *curr = root;

    while (curr != nullptr)
    {
        if (curr->left == nullptr)
        {
            // If no left child, visit this node
            cout << curr->val << " ";
            curr = curr->right;
        }
        else
        {
            // Find the inorder predecessor (rightmost node in left subtree)
            TreeNode *pre = curr->left;
            while (pre->right != nullptr && pre->right != curr)
            {
                pre = pre->right;
            }

            if (pre->right == nullptr)
            {
                // Make current as the right child of its predecessor
                pre->right = curr;
                curr = curr->left;
            }
            else
            {
                // Revert the changes (remove thread)
                pre->right = nullptr;
                cout << curr->val << " ";
                curr = curr->right;
            }
        }
    }
}

