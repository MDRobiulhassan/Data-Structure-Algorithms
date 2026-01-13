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
    // Function to build the binary tree from preorder and inorder
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        // Map to store the index of each value in inorder
        map<int, int> inMap;

        // Fill the map with inorder values and their indices
        for (int i = 0; i < inorder.size(); i++)
        {
            inMap[inorder[i]] = i;
        }

        // Call the recursive helper function
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
    }

private:
    // Recursive function to build tree using preorder and inorder segments
    TreeNode *build(vector<int> &preorder, int preStart, int preEnd,
                    vector<int> &inorder, int inStart, int inEnd, map<int, int> &inMap)
    {

        // Base condition
        if (preStart > preEnd || inStart > inEnd)
            return nullptr;

        // The first element in preorder is root
        TreeNode *root = new TreeNode(preorder[preStart]);

        // Find the root index in inorder
        int inRoot = inMap[root->val];

        // Number of elements in left subtree
        int numsLeft = inRoot - inStart;

        // Recursively build left and right subtrees
        root->left = build(preorder, preStart + 1, preStart + numsLeft,
                           inorder, inStart, inRoot - 1, inMap);
        root->right = build(preorder, preStart + numsLeft + 1, preEnd,
                            inorder, inRoot + 1, inEnd, inMap);

        return root;
    }
};


