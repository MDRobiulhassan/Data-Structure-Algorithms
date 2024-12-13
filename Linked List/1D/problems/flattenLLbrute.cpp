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
    Node *convertArrtoLL(vector<int> a)
    {
        if (a.size() == 0)
            return NULL;
        Node *head = new Node(a[0]), *temp = head;

        for (int i = 1; i < a.size(); i++)
        {
            Node *newNode = new Node(a[i]);
            temp->bottom = newNode;
            temp = newNode;
        }
        return head;
    }
    Node *flatten(Node *root)
    {
        vector<int> a;
        Node *temp = root, *temp2 = root;

        while (temp)
        {
            temp2 = temp;
            while (temp2)
            {
                a.push_back(temp2->data);
                temp2 = temp2->bottom;
            }
            temp = temp->next;
        }

        sort(a.begin(), a.end());

        return convertArrtoLL(a);
    }
};