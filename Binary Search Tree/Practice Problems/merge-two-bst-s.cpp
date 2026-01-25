#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    void inorder(Node *root, vector<int> &v)
    {
        if (!root)
            return;
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }

    vector<int> merge(Node *root1, Node *root2)
    {
        vector<int> v1, v2;
        inorder(root1, v1);
        inorder(root2, v2);

        // merge two sorted arrays in O(n+m)
        vector<int> ans;
        int i = 0, j = 0;
        while (i < v1.size() && j < v2.size())
        {
            if (v1[i] <= v2[j])
                ans.push_back(v1[i++]);
            else
                ans.push_back(v2[j++]);
        }

        while (i < v1.size())
            ans.push_back(v1[i++]);
        while (j < v2.size())
            ans.push_back(v2[j++]);

        return ans;
    }
};
