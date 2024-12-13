#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
class Solution
{
public:
    Node *removeDuplicates(struct Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        Node *temp = head->next, *back = NULL, *front = NULL;
        while (temp)
        {
            back = temp->prev, front = temp->next;
            if (temp->data == back->data)
            {
                back->next = front;
                if (front != NULL)
                    front->prev = back;
                delete temp;
            }
            temp = front;
        }
        return head;
    }
};