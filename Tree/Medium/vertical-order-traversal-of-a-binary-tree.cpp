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
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {

        // nodes[x][y] will store all node values that lie at:
        // x -> vertical column
        // y -> level (row)
        // multiset is used to keep values sorted automatically
        map<int, map<int, multiset<int>>> nodes;

        // Queue for BFS traversal
        // Each element stores:
        // {current node, {column(x), row(y)}}
        queue<pair<TreeNode *, pair<int, int>>> q;

        // Start BFS from root at column = 0, row = 0
        q.push({root, {0, 0}});

        // Standard BFS traversal
        while (!q.empty())
        {

            // Take front element
            auto it = q.front();
            q.pop();

            TreeNode *node = it.first;
            int x = it.second.first;  // column
            int y = it.second.second; // row

            // Insert node value into:
            // column x, row y
            nodes[x][y].insert(node->val);

            // Move left:
            // column decreases by 1, row increases by 1
            if (node->left)
                q.push({node->left, {x - 1, y + 1}});

            // Move right:
            // column increases by 1, row increases by 1
            if (node->right)
                q.push({node->right, {x + 1, y + 1}});
        }

        vector<vector<int>> ans;

        // Iterate columns from leftmost to rightmost
        for (auto it : nodes)
        {
            vector<int> col;

            // Iterate rows from top to bottom
            for (auto iter : it.second)
            {

                // Insert all sorted values at this (column, row)
                col.insert(col.end(),
                           iter.second.begin(),
                           iter.second.end());
            }

            // Add this column to answer
            ans.push_back(col);
        }

        return ans;
    }
};
