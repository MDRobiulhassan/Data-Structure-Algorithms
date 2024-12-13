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
        Node *temp = head, *nextNode = head->next;
        while (temp != NULL && temp->next != NULL)
        {
            while (nextNode && nextNode->data == temp->data)
                nextNode = nextNode->next;
            temp->next = nextNode;
            if (nextNode != NULL)
                nextNode->prev = temp;
            temp = nextNode;
        }
        return head;
    }
};