#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
class Solution
{
public:
    // Function which returns the  root of the flattened linked list.
    Node *mergeLL(Node *list1, Node *list2)
    {
        Node *dummyNode = new Node(-1), *res = dummyNode;
        while (list1 != NULL && list2 != NULL)
        {
            if (list1->data < list2->data)
            {
                res->bottom = list1;
                res = list1;
                list1 = list1->bottom;
            }
            else
            {
                res->bottom = list2;
                res = list2;
                list2 = list2->bottom;
            }
            res->next = NULL;
        }

        if (list1)
            res->bottom = list1;
        else
            res->bottom = list2;
        if (dummyNode->bottom)
        {
            dummyNode->bottom->next = NULL;
        }
        return dummyNode->bottom;
    }
    Node *flatten(Node *root)
    {
        if (root == NULL || root->next == NULL)
            return root;
        Node *mergehead = flatten(root->next);
        root = mergeLL(root, mergehead);
        return root;
    }
};