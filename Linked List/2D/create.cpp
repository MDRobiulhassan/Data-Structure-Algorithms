#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;

    Node(int data, Node *next, Node *back)
    {
        this->data = data;
        this->next = next;
        this->back = back;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->back = NULL;
    }
};

Node *convertarr2DLL(int a[])
{
    Node *head = new Node(a[0]);
    Node *prev = head;

    for (int i = 1; i < 5; i++)
    {
        Node *temp = new Node(a[i], NULL, prev);
        prev->next = temp;
        prev = prev->next;
    }

    return head;
}

void printDLL(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        cout << temp->next << " ";
        cout << temp->back << " ";
        cout << endl;
        temp = temp->next;
    }
}
void printDLLback(Node *head)
{
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->back;
    }
}

int main()
{
    int a[] = {10, 20, 30, 40, 50};
    Node *head = convertarr2DLL(a);
    printDLL(head);
    printDLLback(head);

    return 0;
}