#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


class Solution
{
public:
    bool isSumProperty(Node *root)
    {

        if (!root || (!root->left && !root->right))
            return true;

        bool left = isSumProperty(root->left);
        bool right = isSumProperty(root->right);

        int leftVal = root->left ? root->left->data : 0;
        int rightVal = root->right ? root->right->data : 0;

        return left && right && (root->data == leftVal + rightVal);
    }
};