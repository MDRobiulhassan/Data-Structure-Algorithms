#include <bits/stdc++.h>
using namespace std;

// This structure defines a node in the binary tree
struct TreeNode
{
    // This stores the value of the node
    int val;
    // Pointer to the left child
    TreeNode *left;
    // Pointer to the right child
    TreeNode *right;

    // Constructor initializes node with value
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                   greater<>>
        pq;

    void traverse(TreeNode *node, int row, int col)
    {
        if (!node)
            return;
        pq.push({col, row, node->val});
        traverse(node->left, row + 1, col - 1);
        traverse(node->right, row + 1, col + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        if (!root)
            return {};
        traverse(root, 0, 0);

        vector<vector<int>> ans;
        int currCol = INT_MIN;
        vector<int> colNodes;

        while (!pq.empty())
        {
            auto [col, row, val] = pq.top();
            pq.pop();

            if (col != currCol)
            {
                if (!colNodes.empty())
                    ans.push_back(colNodes);
                colNodes.clear();
                currCol = col;
            }
            colNodes.push_back(val);
        }

        if (!colNodes.empty())
            ans.push_back(colNodes);
        return ans;
    }
};
