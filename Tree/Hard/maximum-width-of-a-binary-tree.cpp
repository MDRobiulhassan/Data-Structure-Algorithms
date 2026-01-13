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
    int widthOfBinaryTree(TreeNode *root)
    {

        // Queue for level-order traversal (BFS)
        // Stores each node along with its "virtual index"
        queue<pair<TreeNode *, long long>> q;

        // Start with root at index 0
        q.push({root, 0});

        // To store the maximum width found
        long long maxWidth = 0;

        // Standard BFS loop
        while (!q.empty())
        {

            // Number of nodes at the current level
            int size = q.size();

            // Index of the first node at this level
            // Used to normalize indices and avoid overflow
            long long minInd = q.front().second;

            // Will store the first and last index of this level
            long long first = 0;
            long long last = 0;

            // Traverse all nodes at the current level
            for (int i = 0; i < size; i++)
            {

                // Get the node
                TreeNode *node = q.front().first;

                // Normalize the index relative to the first node
                long long curInd = q.front().second - minInd;

                // Remove current node from the queue
                q.pop();

                // If this is the first node of the level,
                // record its index
                if (i == 0)
                    first = curInd;

                // If this is the last node of the level,
                // record its index
                if (i == size - 1)
                    last = curInd;

                // Push left child with its calculated index
                if (node->left)
                    q.push({node->left, 2 * curInd + 1});

                // Push right child with its calculated index
                if (node->right)
                    q.push({node->right, 2 * curInd + 2});
            }

            // Width of current level = last - first + 1
            // Update maximum width
            maxWidth = max(maxWidth, last - first + 1);
        }

        // Return the maximum width found
        return (int)maxWidth;
    }
};
