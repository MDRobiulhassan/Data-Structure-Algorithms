#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data, Node *next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

Node *convertarr2DLL(int a[])
{
    Node *head = new Node(a[0]);
    Node *temp = head;

    for (int i = 1; i < 5; i++)
    {
        Node *newNode = new Node(a[i]);
        temp->next = newNode;
        newNode->prev = temp;
        temp = newNode;
    }
    return head;
}

void printDLL(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void printDLLback(Node *head)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
}

Node *inserthead(Node *head, int val)
{
    Node *newNode = new Node(val, head, NULL);
    head->prev = newNode;
    return newNode;
}

int main()
{
    int a[] = {10, 20, 30, 40, 50};
    Node *head = convertarr2DLL(a);
    printDLL(head);
    cout << endl;
    head=inserthead(head, 60);
    printDLL(head);
}