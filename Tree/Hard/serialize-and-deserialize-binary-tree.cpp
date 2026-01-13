#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    // Encodes a tree to a single string (BFS / level-order)
    string serialize(TreeNode *root)
    {
        string ans = "";

        // If tree is empty, return empty string
        if (!root)
            return ans;

        // Queue for level-order traversal
        queue<TreeNode *> q;
        q.push(root);

        // Perform BFS
        while (!q.empty())
        {

            // Process one node at a time
            TreeNode *node = q.front();
            q.pop();

            if (node)
            {
                // Store current node value followed by a comma
                ans += to_string(node->val) + ",";

                // Push both children (even if they are NULL)
                // This preserves tree structure
                q.push(node->left);
                q.push(node->right);
            }
            else
            {
                // Store null marker for missing nodes
                ans += "null,";
            }
        }

        // Final serialized string
        return ans;
    }

    // Decodes your encoded data back to a binary tree
    TreeNode *deserialize(string data)
    {

        // If string is empty, tree is empty
        if (data.size() == 0)
            return NULL;

        // Split the serialized string by commas
        vector<string> vals;
        string temp;

        for (char c : data)
        {
            if (c == ',')
            {
                vals.push_back(temp);
                temp.clear();
            }
            else
            {
                temp += c;
            }
        }

        // First value is always the root
        TreeNode *root = new TreeNode(stoi(vals[0]));

        // Queue to rebuild tree level by level
        queue<TreeNode *> q;
        q.push(root);

        // Index pointing to next child value in vals
        int i = 1;

        // Process nodes in BFS order
        while (!q.empty() && i < vals.size())
        {

            TreeNode *node = q.front();
            q.pop();

            // Left child
            if (vals[i] != "null")
            {
                node->left = new TreeNode(stoi(vals[i]));
                q.push(node->left);
            }
            i++;

            // Right child
            if (i < vals.size() && vals[i] != "null")
            {
                node->right = new TreeNode(stoi(vals[i]));
                q.push(node->right);
            }
            i++;
        }

        // Return reconstructed tree
        return root;
    }
};
