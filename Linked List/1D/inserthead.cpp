#include <bits/stdc++.h>
#include <cstddef>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *array2LL(vector<int> a)
{
    Node *head = new Node(a[0]);
    Node *mover = head;

    for (int i = 1; i < a.size(); i++)
    {
        Node *temp = new Node(a[i]);

        mover->next = temp;
        mover = temp;
    }
    return head;
}

void printLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *insertHead(Node *head, int val)
{
    return new Node(val, head);
}

int main()
{
    vector<int> a;
    for (int i = 1; i <= 5; i++)
    {
        a.push_back(i);
    }

    Node *head = array2LL(a);
    cout << "Before Insert : ";
    printLL(head);
    cout << endl;
    cout << "After Insert : ";
    head = insertHead(head, 10);
    printLL(head);
}