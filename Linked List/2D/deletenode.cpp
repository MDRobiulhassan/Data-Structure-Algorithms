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

Node *deletenode(Node *head, int val)
{
    if (head == NULL)
        return NULL;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == val)
            break;
        temp = temp->next;
    }

    if (temp == NULL)
        return head; // Value not found in DLL

    Node *front = temp->next;
    Node *back = temp->prev;

    // single element
    if (front == NULL && back == NULL)
    {
        delete temp;
        return NULL;
    }

    // head
    if (back == NULL)
    {
        head = front;
        front->prev = NULL;
        delete temp;
        return head;
    }

    // tail
    if (front == NULL)
    {
        back->next = NULL;
        delete temp;
        return head;
    }

    back->next = front;
    front->prev = back;
    delete temp;
    return head;
}

int main()
{
    int a[] = {10, 20, 30, 40, 50};
    Node *head = convertarr2DLL(a);
    printDLL(head);
    cout << endl;
    head = deletenode(head, 500);
    printDLL(head);
    cout << endl;
    printDLLback(head);
}