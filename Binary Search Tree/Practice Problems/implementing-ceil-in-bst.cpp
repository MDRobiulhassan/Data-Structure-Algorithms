#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
public:
    int findCeil(Node *root, int x)
    {
        int ceil = -1;

        while (root)
        {
            if (root->data == x)
                return x;

            if (x < root->data)
            {
                ceil = root->data;
                root = root->left;
            }
            else
            {

                root = root->right;
            }
        }
        return ceil;
    }
};