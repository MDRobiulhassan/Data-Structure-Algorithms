#include <bits/stdc++.h>
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

Node *insertLL(int n)
{
    Node *head = NULL;
    Node *temp = NULL;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (head == NULL)
        {
            head = new Node(x);
            temp = head;
        }
        else
        {
            Node *newNode = new Node(x);
            temp->next = newNode;
            temp=newNode;
        }
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

int main()
{
    int n;
    cin >> n;

    Node *head = insertLL(n);
    printLL(head);
}