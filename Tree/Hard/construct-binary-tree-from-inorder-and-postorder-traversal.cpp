#include <bits/stdc++.h>
using namespace std;

// TreeNode structure
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    // Constructor to initialize a node
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    TreeNode *build(vector<int> &postorder, int postStart, int postEnd,
                    vector<int> &inorder, int inStart, int inEnd,
                    map<int, int> &inMap)
    {
        if (postStart > postEnd || inStart > inEnd)
            return NULL;

        TreeNode *root = new TreeNode(postorder[postEnd]);

        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;

        root->left = build(postorder, postStart, postStart + numsLeft - 1,
                           inorder, inStart, inRoot - 1, inMap);
        root->right = build(postorder, postStart + numsLeft, postEnd - 1,
                            inorder, inRoot + 1, inEnd, inMap);

        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();
        int m = postorder.size();

        map<int, int> inMap;

        for (int i = 0; i < n; i++)
            inMap[inorder[i]] = i;

        return build(postorder, 0, m - 1, inorder, 0, n - 1, inMap);
    }
};