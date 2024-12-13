#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
class Solution
{
public:
    int helper(Node *head)
    {
        if (head == NULL)
            return 1;
        int carry = helper(head->next);
        head->data += carry;
        if (head->data < 10)
            return 0;
        head->data = 0;
        return 1;
    }
    Node *addOne(Node *head)
    {
        int carry = helper(head);
        if (carry == 1)
        {
            Node *newNode = new Node(1);
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
};