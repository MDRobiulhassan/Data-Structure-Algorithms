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
    int floor(Node *root, int x)
    {
        int floor = -1;

        while (root)
        {
            if (root->data == x)
                return x;

            if (x > root->data)
            {
                floor = root->data;
                root = root->right;
            }
            else
            {
                root = root->left;
            }
        }

        return floor;
    }
};