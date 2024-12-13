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
    Node *reverse(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        Node *temp = head, *prev = NULL, *front = NULL;
        while (temp)
        {
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    Node *addOne(Node *head)
    {
        head = reverse(head);
        Node *temp = head;
        int carry = 1;

        while (temp)
        {
            temp->data += carry;
            if (temp->data == 10)
            {
                temp->data = 0;
                carry = 1;
            }
            else
            {
                carry = 0;
                break;
            }
            temp = temp->next;
        }
        head = reverse(head);

        if (carry == 1)
        {
            Node *newNode = new Node(1);
            newNode->next = head;
            return newNode;
        }

        return head;
    }
};