#include <bits/stdc++.h>
using namespace std;

struct Node
{
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
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    int inOrderSuccessor(Node *root, Node *x)
    {
        int succ = -1;

        while (root)
        {
            if (x->data < root->data)
            {
                succ = root->data;
                root = root->left;
            }
            else
                root = root->right;
        }

        return succ;
    }
};